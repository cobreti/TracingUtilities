#ifndef IMESSAGEHANDLER_HPP
#define IMESSAGEHANDLER_HPP

namespace TraceServer
{
    namespace Messages
    {
        class Message;
    }

    class IMessageHandler
    {
    public:

        virtual void handleMessage(const Messages::Message& msg) = 0;
    };
}


#endif // IMESSAGEHANDLER_HPP
