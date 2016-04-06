#ifndef MONITORPANELMSGHANDLER_HPP
#define MONITORPANELMSGHANDLER_HPP

#include <QtCore>
#include "server.hpp"
#include "messages/Message.hpp"

class MonitorPanel;

class MonitorPanelMsgHandler : public QObject, TraceServer::IMessageHandler
{
    Q_OBJECT

public:
    MonitorPanelMsgHandler(MonitorPanel &panel, TraceServer::MessageBus& msgBus);
    virtual ~MonitorPanelMsgHandler();

public: // IMessageHandler

    virtual void handleMessage(const TraceServer::Messages::Message& msg) override;

signals:

    void connectionsCountChanged(int count);

protected:

    MonitorPanel                    &panel_;
    TraceServer::MessageBus         &msgBus_;
};

#endif // MONITORPANELMSGHANDLER_HPP

