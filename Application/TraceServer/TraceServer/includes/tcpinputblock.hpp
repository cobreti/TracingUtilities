#ifndef TCPINPUTBLOCK_HPP
#define TCPINPUTBLOCK_HPP

#include <QtCore>
#include "inputblock.hpp"

namespace TraceServer
{
    class TcpInputBlock : public InputBlock
    {
        Q_OBJECT

    public:
        TcpInputBlock( QString name, PortT port );

        virtual void start() override;
        virtual void stop() override;

    public slots:

        void onNewConnection();

    protected:

        PortT           port_;
        QHostAddress    address_;
        QTcpServer      *pServer_;
        QThreadPool     threadPool_;
    };
}


#endif // TCPINPUTBLOCK_HPP
