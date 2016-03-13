#include "server.hpp"
#include "inputblockMgr.hpp"

namespace TraceServer
{
    Server::Server() :
        inputBlockMgr_{messageBus_}
    {
    }

    Server::~Server()
    {
    }
}

