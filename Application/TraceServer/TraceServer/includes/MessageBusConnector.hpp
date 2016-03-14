#ifndef MESSAGEBUSCONNECTOR_HPP
#define MESSAGEBUSCONNECTOR_HPP

#include <QtCore>
#include "messagebus.hpp"

namespace TraceServer
{
    class MessageBusConnector : public QObject
    {
        Q_OBJECT

    public:
        MessageBusConnector( MessageBus &bus );

    protected slots:

        void onMessage( MessageBus::MessageContainer &msgContainer );

    protected:

        MessageBus      &bus_;
    };
}

#endif // MESSAGEBUSCONNECTOR_HPP
