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

    class MBCore;

    /**
     * @brief The MessageBus class
     */
    class MessageBus : public QObject
    {
        Q_OBJECT

    public:
        MessageBus();

        MessageBus(const MessageBus&) = delete;
        const MessageBus& operator = (const MessageBus&) = delete;

        void send( const MsgBucket &msgBucket );

        void start();
        void stop();

    protected slots:

        void onMBCoreStarted();

    private:

        MBCore              *pCore_;
    };


    /**
     * @brief The MBCore class
     */
    class MBCore : public QThread
    {
        Q_OBJECT

    public:
        MBCore(MessageBus &owner);

        void start();
        void stop();

        void push( Messages::Message *pMsg );

    protected:

        virtual void run() override;

    protected:

    protected slots:

        void processMessages();

    private:
        MessageBus      &owner_;
        MessageQueue    msgQueue_;
        QEventLoop      *pEventLoop_;
        QTimer          checkMsgTimer_;
    };
}

#endif // MESSAGEBUS_HPP
