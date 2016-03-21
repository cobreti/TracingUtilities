#include "includes/socketreceiver.hpp"

#include <algorithm>

namespace TraceServer
{
    SocketReceiver::SocketReceiver(QTcpSocket *pSocket) : QObject(),
        pSocket_{pSocket},
        connected_{true},
        pEventLoop_{nullptr},
        dataBuffer_{kBufferSize},
        dataParser_{&primaryStorage_, kBufferSize},
        bytesRead_{0}
    {
        setAutoDelete(false);
    }


    SocketReceiver::~SocketReceiver()
    {
        delete pSocket_;
    }


    void SocketReceiver::run()
    {       
        pEventLoop_ = new QEventLoop();

        connect(    pSocket_, SIGNAL(connected()),
                    this, SLOT(onSocketConnected()) );
        connect(    pSocket_, SIGNAL(disconnected()),
                    this, SLOT(onSocketDisconnected()) );
        connect(    pSocket_, SIGNAL(readyRead()),
                    this, SLOT(onReadyRead()) );
        connect(    pSocket_, SIGNAL(error(QAbstractSocket::SocketError)),
                    this, SLOT(onSocketError(QAbstractSocket::SocketError)) );
        connect(    &monitorTimer_, SIGNAL(timeout()),
                    this, SLOT(onMonitorTimeout()) );


        qDebug() << "SocketReceiver : running loop starting";

        pEventLoop_->exec();

        qDebug() << "SocketReceiver : running loop ending";
    }

    void SocketReceiver::onSocketConnected()
    {
        qDebug() << "SocketReceiver : socket connected";
    }

    void SocketReceiver::onSocketDisconnected()
    {
        qDebug() << "SocketReceiver : socket disconnected";

        emit connectionTerminated(this);

        monitorTimer_.stop();
        pEventLoop_->exit();
    }

    void SocketReceiver::onReadyRead()
    {
        if ( !monitorTimer_.isActive() ) {
            monitorTimer_.start(500);
        }

        int bytesAvail = 0;

        while ( (bytesAvail = pSocket_->bytesAvailable()) > 0 )
        {
//            qDebug() << "bytes available to read : " << bytesAvail;

            int bytesToRead = std::min( dataBuffer_.availableSize(), bytesAvail );

//            qDebug() << "reading " << bytesToRead << " bytes";

            pSocket_->read( dataBuffer_.getWritePosForData(bytesToRead), bytesToRead );
            bytesRead_ += bytesToRead;

            if ( dataBuffer_.availableSize() == 0 )
                processBuffer();
        }

        if ( !dataBuffer_.empty() )
        {
            processBuffer();
        }
    }

    void SocketReceiver::onSocketError(QAbstractSocket::SocketError socketError)
    {
        qDebug() << "SocketReceiver : socket error = " << socketError;
    }

    void SocketReceiver::onMonitorTimeout()
    {
        qDebug() << bytesRead_ << " for interval of " << monitorTimer_.interval() << "ms";
        bytesRead_ = 0;
    }

    void SocketReceiver::processBuffer()
    {
        dataParser_.parse( dataBuffer_.bufferPos(), dataBuffer_.dataSize() );
        dataBuffer_.reset();
    }
}

