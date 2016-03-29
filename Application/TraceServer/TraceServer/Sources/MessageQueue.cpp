#include "MessageQueue.hpp"

namespace TraceServer
{
    MessageQueue::MessageQueue()
    {
    }


    MessageQueue::~MessageQueue()
    {
    }


    void MessageQueue::add(Messages::Message *pMsg)
    {
        if (pMsg != nullptr)
        {
            QMutexLocker        locker(&lock_);
            messages_.push_back( MessagePtr(pMsg) );
        }
    }

    MessageQueue::MessagePtr MessageQueue::pop()
    {
        QMutexLocker        locker(&lock_);

        if ( messages_.empty() )
            return MessagePtr();

        auto ret = messages_.front();
        messages_.pop_front();
        return ret;
    }

    bool MessageQueue::empty() const
    {
        return messages_.empty();
    }
}
