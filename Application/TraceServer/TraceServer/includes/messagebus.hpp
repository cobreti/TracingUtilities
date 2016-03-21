#ifndef MESSAGEBUS_HPP
#define MESSAGEBUS_HPP

#include <QtCore>
#include "MessageQueue.hpp"

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

    signals:

    protected slots:

    private:

        class MBCore : public QThread
        {
        public:
            MBCore(MessageBus &owner);

        protected:

            virtual void run() override;

        private:
            MessageBus      &owner_;
        };

    private:

        MessageQueue        *pIn_;
        MessageQueue        *pOut_;
        QMutex              queueSwapMutex_;
    };
}

#endif // MESSAGEBUS_HPP
