#include "includes/socketreceiver.hpp"

namespace TraceServer
{
    SocketReceiver::SocketReceiver(QTcpSocket *pSocket) : QObject(),
        pSocket_{pSocket},
        connected_{true}
    {

        connect(    pSocket_, SIGNAL(disconnected()),
                    this, SLOT(onSocketDisconnected()) );
    }


    SocketReceiver::~SocketReceiver()
    {
        delete pSocket_;
    }


    void SocketReceiver::run()
    {
        qDebug() << "SocketReceiver : running loop starting";

        while ( connected_ )
        {
            bool dataReady = pSocket_->waitForReadyRead();
            if ( dataReady )
            {
                QByteArray data = pSocket_->readAll();
                qDebug() << " read " << data.size() << " bytes from socket";
            }
        }

        qDebug() << "SocketReceiver : running loop ending";
    }

    void SocketReceiver::onSocketDisconnected()
    {
        qDebug() << "SocketReceiver : socket disconnected";

        connected_ = false;
    }
}

