#include "MessageBusConnector.hpp"
#include "Messages/ConnectionsCountChanged.hpp"

namespace TraceServer
{
    MessageBusConnector::MessageBusConnector(MessageBus &bus) :
        bus_{bus}
    {
        connect(    &bus_, SIGNAL(newMessage(MessageBus::MessageContainer&)),
                    this, SLOT(onMessage(MessageBus::MessageContainer&)) );
    }


    void MessageBusConnector::onMessage(MessageBus::MessageContainer &msgContainer)
    {
        auto &msg = msgContainer.msg();

        const Messages::ConnectionsCountChanged   &cccMsg = dynamic_cast<const Messages::ConnectionsCountChanged&>(msg);
    }
}
