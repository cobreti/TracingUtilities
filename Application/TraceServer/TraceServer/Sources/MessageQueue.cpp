#include "MessageQueue.hpp"

namespace TraceServer
{
    MessageQueue::MessageQueue()
    {
    }


    MessageQueue::~MessageQueue()
    {
    }


    void MessageQueue::add(const Messages::Message &msg)
    {
        Messages::Message*  pMsg = msg.cloneToPtr();
        if (pMsg != nullptr)
        {
            messages_.push_back( MessagePtr(pMsg) );
        }
    }
}
