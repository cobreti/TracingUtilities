#ifndef INPUTBLOCK_HPP
#define INPUTBLOCK_HPP

#include <string>
#include <qtcore>
#include <QtNetwork>

namespace TraceServer
{
    class InputBlock : QObject
    {
        Q_OBJECT

    public:

        using InputBlockNameT = std::string;
        using PortT = quint16;

    public:
        InputBlock( InputBlockNameT name, PortT port );

        InputBlock(const InputBlock&) = delete;
        InputBlock operator = (const InputBlock&) = delete;

        const InputBlockNameT& name() { return name_; }

        void start();
        void stop();

    protected:

        InputBlockNameT name_;
        PortT           port_;
        QHostAddress    address_;
        QTcpServer      server_;
    };
}

#endif // INPUTBLOCK_HPP
