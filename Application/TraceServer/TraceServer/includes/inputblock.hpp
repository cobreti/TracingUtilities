#ifndef INPUTBLOCK_HPP
#define INPUTBLOCK_HPP

#include <string>
#include <qtcore>
#include <QtNetwork>

namespace TraceServer
{
    class InputBlock : public QObject
    {
        Q_OBJECT

    public:

        using PortT = quint16;

    public:
        InputBlock( QString name );

        InputBlock(const InputBlock&) = delete;
        InputBlock operator = (const InputBlock&) = delete;

        const QString& name() { return name_; }

        virtual void start();
        virtual void stop();

    protected:

        QString         name_;
    };
}

#endif // INPUTBLOCK_HPP
