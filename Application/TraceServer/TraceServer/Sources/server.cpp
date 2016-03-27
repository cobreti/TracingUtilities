#include "server.hpp"
#include "inputblockMgr.hpp"

namespace TraceServer
{
    Server::Server() : QObject(),
        inputBlockMgr_{messageBus_}
    {
    }

    Server::~Server()
    {
    }


    void Server::start()
    {
        QCoreApplication *pApp = QCoreApplication::instance();

        connect(    pApp, SIGNAL(aboutToQuit()),
                    this, SLOT(onAppQuit()) );

        messageBus_.start();
    }

    void Server::onAppQuit()
    {
        messageBus_.stop();
    }
}

