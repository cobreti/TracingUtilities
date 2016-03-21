#ifndef MESSAGEQUEUE_HPP
#define MESSAGEQUEUE_HPP

#include <list>
#include "messages/Message.hpp"


namespace TraceServer
{
    class MessageQueue
    {
    public:
        MessageQueue();
        virtual ~MessageQueue();

        MessageQueue(const MessageQueue&) = delete;
        const MessageQueue& operator = (const MessageQueue&) = delete;

        void add(const Messages::Message &msg);

    private:

        using MessagePtr = std::shared_ptr<Messages::Message>;
        using MessageList = std::list<MessagePtr>;

    private:

        MessageList     messages_;
    };
}

#endif // MESSAGEQUEUE_HPP
