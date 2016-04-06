#include <QtCore>

#include "includes/MessageBus.hpp"


namespace TraceServer
{

    MessageBus::MessageBus() :
        pCore_{nullptr}
    {
    }

    void MessageBus::send(const MsgBucket &msgBucket)
    {
        qDebug() << "adding message";

        pCore_->push( msgBucket.detach() );

        qDebug() << "new message added";
    }

    void MessageBus::start()
    {
        pCore_ = new MBCore(*this);

        pCore_->start();
    }

    void MessageBus::stop()
    {
       if ( pCore_ )
       {
           pCore_->stop();
       }
    }

    void MessageBus::addHandler(IMessageHandler *pHandler)
    {
        if ( pCore_ )
            pCore_->handlers().add(pHandler);
    }

    void MessageBus::removeHandler(IMessageHandler *pHandler)
    {
        if ( pCore_ )
            pCore_->handlers().remove(pHandler);
    }

    void MessageBus::onMBCoreStarted()
    {
        qDebug() << "MBCore started";
    }

    MBCore::MBCore(MessageBus &owner) :
        QThread(),
        owner_{owner},
        pEventLoop_{nullptr}
    {
    }

    void MBCore::start()
    {
        connect(    &checkMsgTimer_, SIGNAL(timeout()),
                    this, SLOT(processMessages()) );

        checkMsgTimer_.setInterval(250);
        checkMsgTimer_.start();

        QThread::start();
    }

    void MBCore::stop()
    {
        if (pEventLoop_)
        {
            pEventLoop_->exit();
        }
    }

    void MBCore::push(Messages::Message *pMsg)
    {
        msgQueue_.add(pMsg);
    }

    void MBCore::run()
    {
        pEventLoop_ = new QEventLoop();
        pEventLoop_->exec();

        this->exit();
    }

    void MBCore::processMessages()
    {
        checkMsgTimer_.stop();

        while (auto pMsg = msgQueue_.pop())
        {
            msgHandlers_.handleMessage(*pMsg);
        }

        checkMsgTimer_.start();
    }

}
