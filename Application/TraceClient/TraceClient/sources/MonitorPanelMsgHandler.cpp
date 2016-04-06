#include "MonitorPanelMsgHandler.hpp"
#include "messages/ConnectionsCountChanged.hpp"

MonitorPanelMsgHandler::MonitorPanelMsgHandler(MonitorPanel &panel, TraceServer::MessageBus &msgBus) : QObject(),
    panel_{panel},
    msgBus_{msgBus}
{
    msgBus_.addHandler(this);
}


MonitorPanelMsgHandler::~MonitorPanelMsgHandler()
{
    msgBus_.removeHandler(this);
}

void MonitorPanelMsgHandler::handleMessage(const TraceServer::Messages::Message &msg)
{
    switch (msg.id())
    {
        case TraceServer::Messages::IDs::kConnectionsCountChanged:
            const auto &rMsg = static_cast<const TraceServer::Messages::ConnectionsCountChanged&>(msg);
            emit connectionsCountChanged(rMsg.count());
            break;
    }
}
