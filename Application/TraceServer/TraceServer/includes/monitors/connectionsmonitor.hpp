#ifndef CONNECTIONSMONITOR_HPP
#define CONNECTIONSMONITOR_HPP

#include <QtCore>

namespace TraceServer
{
    class InputBlock;
    class MessageBus;
    class SocketReceiver;

    class ConnectionsMonitor : public QObject
    {
        Q_OBJECT

    public:

        ConnectionsMonitor(InputBlock& block, MessageBus& msgBus);

        ConnectionsMonitor(ConnectionsMonitor&) = delete;
        const ConnectionsMonitor& operator = (const ConnectionsMonitor&) = delete;

    signals:

    protected slots:

        void onNewConnection(SocketReceiver* pReceiver);
        void onConnectionClosed(SocketReceiver* pReceiver);

    protected:

        InputBlock      &inputBlock_;
        MessageBus      &msgBus_;
        int             connectionsCount_;
    };
}

#endif // CONNECTIONSMONITOR_HPP
