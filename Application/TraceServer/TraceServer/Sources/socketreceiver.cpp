#include "includes/socketreceiver.hpp"

namespace TraceServer
{
    SocketReceiver::SocketReceiver(QTcpSocket *pSocket) : QObject(),
        pSocket_{pSocket},
        connected_{true},
        pEventLoop_{nullptr},
        pBuffer_{nullptr},
        bufferSize_{5}
    {

    }


    SocketReceiver::~SocketReceiver()
    {
        delete pSocket_;
    }


    void SocketReceiver::run()
    {       
        pEventLoop_ = new QEventLoop();

        pBuffer_ = new char[bufferSize_];

        connect(    pSocket_, SIGNAL(connected()),
                    this, SLOT(onSocketConnected()) );
        connect(    pSocket_, SIGNAL(disconnected()),
                    this, SLOT(onSocketDisconnected()) );
        connect(    pSocket_, SIGNAL(readyRead()),
                    this, SLOT(onReadyRead()) );
        connect(    pSocket_, SIGNAL(error(QAbstractSocket::SocketError)),
                    this, SLOT(onSocketError(QAbstractSocket::SocketError)) );


        qDebug() << "SocketReceiver : running loop starting";

        pEventLoop_->exec();

        delete[] pBuffer_;

        qDebug() << "SocketReceiver : running loop ending";
    }

    void SocketReceiver::onSocketConnected()
    {
        qDebug() << "SocketReceiver : socket connected";
    }

    void SocketReceiver::onSocketDisconnected()
    {
        qDebug() << "SocketReceiver : socket disconnected";

        pEventLoop_->exit();
//        delete this;
    }

    void SocketReceiver::onReadyRead()
    {
        qint64 bytesAvail = 0;

        while ( bytesAvail = pSocket_->bytesAvailable() )
        {
            qDebug() << "bytes available to read : " << bytesAvail;
            qDebug() << "reading " << bufferSize_ << " bytes from socket";
            pSocket_->read(pBuffer_, bufferSize_);
        }
    }

    void SocketReceiver::onSocketError(QAbstractSocket::SocketError socketError)
    {
        qDebug() << "SocketReceiver : socket error = " << socketError;
    }
}

