#ifndef MESSAGEBUS_HPP
#define MESSAGEBUS_HPP

#include <QtCore>

namespace TraceServer
{
    class MessageBus : public QObject
    {
        Q_OBJECT

    public:
        MessageBus();

        MessageBus(const MessageBus&) = delete;
        const MessageBus& operator = (const MessageBus&) = delete;

    signals:

    protected slots:

    };
}

#endif // MESSAGEBUS_HPP
