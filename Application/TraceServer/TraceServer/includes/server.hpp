#ifndef SERVER_HPP
#define SERVER_HPP

#include <QtCore>

#include "inputblockMgr.hpp"
#include "messagebus.hpp"

namespace TraceServer
{
    class InputBlockMgr;

    class Server : public QObject
    {
        Q_OBJECT

    public:
        Server();
        virtual ~Server();

        Server(const Server&) = delete;
        Server const operator = (const Server&) = delete;

        void start();

        InputBlockMgr& inputBlocks() { return inputBlockMgr_; }
        MessageBus& messageBus() { return messageBus_; }

    protected slots:

        void onAppQuit();

    protected:
        MessageBus          messageBus_;
        InputBlockMgr       inputBlockMgr_;
    };
}

#endif // SERVER_HPP
