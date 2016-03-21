#include "includes/MessageBus.hpp"


namespace TraceServer
{

    MessageBus::MessageBus()
    {
        pIn_ = new MessageQueue();
        pOut_ = new MessageQueue();
    }


    void MessageBus::send(const Messages::Message &msg)
    {
    }


    MessageBus::MBCore::MBCore(MessageBus &owner) :
        QThread(),
        owner_{owner}
    {
    }

    void MessageBus::MBCore::run()
    {

    }
}
