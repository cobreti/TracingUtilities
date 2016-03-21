#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "messages/MessageIDs.hpp"

namespace TraceServer
{
    namespace Messages
    {
        class Message
        {
        public:
            Message(MessageID id);
            Message(const Message&);
            virtual ~Message();

            const Message& operator = (const Message&) = delete;

            MessageID id() const noexcept { return id_; }

            virtual Message* cloneToPtr() const = 0;

        private:

            MessageID           id_;
        };
    }
}

#endif // MESSAGE_HPP
