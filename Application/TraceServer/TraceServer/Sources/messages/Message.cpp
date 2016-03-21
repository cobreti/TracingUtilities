#include "messages/Message.hpp"

namespace TraceServer
{
    namespace Messages
    {
        Message::Message(MessageID id) : id_{id}
        {
        }

        Message::Message(const Message &msg) : id_{msg.id_}
        {

        }

        Message::~Message()
        {

        }
    }
}
