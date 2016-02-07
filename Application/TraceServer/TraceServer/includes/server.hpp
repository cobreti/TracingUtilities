#ifndef SERVER_HPP
#define SERVER_HPP

#include "inputblockMgr.hpp"

namespace TraceServer
{
    class InputBlockMgr;

    class Server final
    {
    public:
        Server();
        ~Server();

        Server(const Server&) = delete;
        Server const operator = (const Server&) = delete;

        InputBlockMgr& inputBlocks() { return inputBlockMgr_; }

    protected:
        InputBlockMgr       inputBlockMgr_;
    };
}

#endif // SERVER_HPP
