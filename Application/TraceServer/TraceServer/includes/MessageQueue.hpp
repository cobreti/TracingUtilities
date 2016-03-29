#ifndef MESSAGEQUEUE_HPP
#define MESSAGEQUEUE_HPP

#include <QtCore>

#include <list>
#include "MsgBucket.hpp"

namespace TraceServer
{
    class MessageQueue
    {
    public:
        using MessagePtr = std::shared_ptr<Messages::Message>;

    public:
        MessageQueue();
        virtual ~MessageQueue();

        MessageQueue(const MessageQueue&) = delete;
        const MessageQueue& operator = (const MessageQueue&) = delete;

        void add(Messages::Message *pMsg);
        MessagePtr pop();
        bool empty() const;

    private:

        using MessageList = std::list<MessagePtr>;

    private:

        QMutex          lock_;
        MessageList     messages_;
    };
}

#endif // MESSAGEQUEUE_HPP
