#include <QtCore>

#include "includes/MessageBus.hpp"


namespace TraceServer
{

    MessageBus::MessageBus() :
        pCore_{nullptr}
    {
    }

    void MessageBus::send(const Messages::Message &msg)
    {
        qDebug() << "adding message";

        pCore_->push(msg);

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

    void MBCore::push( const Messages::Message &msg)
    {
        msgQueue_.add(msg);
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
            qDebug() << "processing message";
            QThread::msleep(500);
        }

        checkMsgTimer_.start();
    }

}
