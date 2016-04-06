#ifndef MESSAGEHANDLERS_HPP
#define MESSAGEHANDLERS_HPP

#include <QtCore>

#include "messages/IMessageHandler.hpp"
#include <set>

namespace TraceServer
{
    class MessageHandlers : public IMessageHandler
    {
    public:
        MessageHandlers();
        ~MessageHandlers();

        MessageHandlers(const MessageHandlers&) = delete;
        const MessageHandlers& operator = (const MessageHandlers&) = delete;

        void add( IMessageHandler *pHandler );
        void remove( IMessageHandler *pHandler );

    public: // IMessageHandler interface

        virtual void handleMessage(const Messages::Message &msg) override;

    protected:

        using HandlersSet = std::set<IMessageHandler*>;

    protected:

        QMutex          mutex_;
        HandlersSet     handlers_;
    };
}

#endif // MESSAGEHANDLERS_HPP
