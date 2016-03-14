#include "includes/MessageBus.hpp"


namespace TraceServer
{

    MessageBus::MessageBus()
    {

    }


    void MessageBus::send(const Messages::Message &msg)
    {
        MessageContainer        container(msg);
        emit newMessage(container);
//        emit newMessage(msg);
    }
}
