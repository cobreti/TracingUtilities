#include "inputblockmgr.hpp"
#include "monitors/connectionsmonitor.hpp"
#include "exceptions/itemalreadyexistsincontainer.hpp"
#include "exceptions/iteminsertionfailure.hpp"

namespace TraceServer
{

    InputBlockMgr::InputBlockMgr(MessageBus &msgBus) :
        msgBus_{msgBus}
    {

    }


    InputBlockMgr::~InputBlockMgr()
    {

    }


    void InputBlockMgr::add( InputBlock* pBlock )
    {
        if ( nullptr == pBlock )
        {
            throw std::invalid_argument("null InputBlock pointer");
        }

        auto name = pBlock->name();

        if ( inputBlocks_.count(name) > 0 )
        {
            throw Exceptions::ItemAlreadyInContainer("given item is already in container");
        }

        ConnectionsMonitor *pMonitor = new ConnectionsMonitor(*pBlock, msgBus_);

        auto res = inputBlocks_.insert( std::make_pair(name, InputBlockEntry(pBlock, pMonitor)) );
        if ( !res.second )
        {
            throw Exceptions::ItemInsertionFailure("failure to add input block");
            delete pMonitor;
        }
    }


    void InputBlockMgr::startAll()
    {
        for (auto p : inputBlocks_)
        {
            p.second.inputBlock()->start();
        }
    }


    void InputBlockMgr::stopAll()
    {
        for (auto p : inputBlocks_)
        {
            p.second.inputBlock()->stop();
        }
    }
}
