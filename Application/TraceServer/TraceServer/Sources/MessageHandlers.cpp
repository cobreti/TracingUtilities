#include "MessageHandlers.hpp"


namespace TraceServer
{

    MessageHandlers::MessageHandlers()
    {

    }


    MessageHandlers::~MessageHandlers()
    {

    }


    void MessageHandlers::add(IMessageHandler *pHandler)
    {
        QMutexLocker        locker(&mutex_);

        handlers_.insert(pHandler);
    }


    void MessageHandlers::remove(IMessageHandler *pHandler)
    {
        QMutexLocker        locker(&mutex_);

        handlers_.erase(pHandler);
    }


    void MessageHandlers::handleMessage(const Messages::Message &msg)
    {
        for (auto it = std::begin(handlers_); it != std::end(handlers_); it++)
        {
            (*it)->handleMessage(msg);
        }
    }
}

