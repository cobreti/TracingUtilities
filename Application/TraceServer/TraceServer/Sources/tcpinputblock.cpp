#include "tcpinputblock.hpp"
#include "includes/networkutility.hpp"
#include "includes/socketreceiver.hpp"

namespace TraceServer
{
    TcpInputBlock::TcpInputBlock(QString name, PortT port) : InputBlock(name),
        port_{port},
        pServer_{nullptr}
    {

    }

    void TcpInputBlock::start()
    {
        pServer_ = new QTcpServer();

        connect(    pServer_, SIGNAL(newConnection()),
                    this, SLOT(onNewConnection()) );

        if ( pServer_->isListening() )
        {
            return;
        }

        address_ = NetworkUtility().getHostAddress();

        bool ret = pServer_->listen(address_, port_);
        if ( !ret )
        {
            qCritical() << "unable to start server on address : " << address_ << " and port : " << port_;
        }
    }

    void TcpInputBlock::stop()
    {
        pServer_->close();
        delete pServer_;
        pServer_ = nullptr;
    }

    void TcpInputBlock::onNewConnection()
    {
        qDebug() << "new connection available";

        QTcpSocket* pSocket = pServer_->nextPendingConnection();
        while ( pSocket )
        {
            SocketReceiver* pReceiver = new SocketReceiver(pSocket);
            threadPool_.start(pReceiver);

            pSocket = pServer_->nextPendingConnection();
        }
    }
}


