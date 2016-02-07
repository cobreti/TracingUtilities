#include "inputblock.hpp"

namespace TraceServer
{

    InputBlock::InputBlock( InputBlockNameT name, PortT port ) :
        name_{name},
        port_{port}
    {

    }

    void InputBlock::start()
    {
        if ( server_.isListening() )
        {
            return;
        }

        auto addresses = QNetworkInterface::allAddresses();

        foreach (auto addr, addresses)
        {
            if (addr.protocol() == QAbstractSocket::IPv4Protocol && !addr.isLoopback() )
            {
                address_ = addr;
                qDebug() << "server IPv4 address found : " << addr;
                break;
            }
        }

        bool ret = server_.listen(address_, port_);
        if ( !ret )
        {
            qCritical() << "unable to start server on address : " << address_ << " and port : " << port_;
        }
    }

    void InputBlock::stop()
    {
        server_.close();
    }
}

