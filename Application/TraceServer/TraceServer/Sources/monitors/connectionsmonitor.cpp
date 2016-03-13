#include "includes/Monitors/ConnectionsMonitor.hpp"
#include "includes/socketreceiver.hpp"
#include "includes/inputblock.hpp"

namespace TraceServer
{
    ConnectionsMonitor::ConnectionsMonitor(InputBlock &block, MessageBus &msgBus) :
        inputBlock_{block},
        msgBus_{msgBus},
        connectionsCount_{0}
    {
        connect(    &block, SIGNAL(newConnection(SocketReceiver*)),
                    this, SLOT(onNewConnection(SocketReceiver*)) );
    }


    void ConnectionsMonitor::onNewConnection(SocketReceiver *pReceiver)
    {
        connect(    pReceiver, SIGNAL(connectionTerminated(SocketReceiver*)),
                    this, SLOT(onConnectionClosed(SocketReceiver*)) );

        ++ connectionsCount_;

        qDebug() << "ConnectionsMonitor -- connections count now : " << connectionsCount_;
    }


    void ConnectionsMonitor::onConnectionClosed(SocketReceiver *pReceiver)
    {
        disconnect( pReceiver, SIGNAL(connectionTerminated(SocketReceiver*)),
                    this, SLOT(onConnectionClosed(SocketReceiver*)) );

        -- connectionsCount_;

        qDebug() << "ConnectionsMonitor -- connections count now : " << connectionsCount_;
    }
}
