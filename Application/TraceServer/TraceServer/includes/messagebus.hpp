#ifndef MESSAGEBUS_HPP
#define MESSAGEBUS_HPP

#include <QtCore>
#include "messages/Message.hpp"

namespace TraceServer
{
    namespace Messages
    {
        class Message;
    }


    class MessageBus : public QObject
    {
        Q_OBJECT

    public:
        MessageBus();

        MessageBus(const MessageBus&) = delete;
        const MessageBus& operator = (const MessageBus&) = delete;

        void send( const Messages::Message &msg );

    public:

        friend class MessageBusConnector;

        class MessageContainer
        {
        public:
            MessageContainer( const Messages::Message &msg ) : msg_{msg} {}
            MessageContainer(const MessageContainer& msgContainer) : msg_{msgContainer.msg_} {}

            const Messages::Message& msg() { return msg_; }

        protected:
            const Messages::Message   &msg_;
        };

    signals:

        void newMessage( MessageBus::MessageContainer &msgContainer );

    protected slots:

    };
}

#endif // MESSAGEBUS_HPP
