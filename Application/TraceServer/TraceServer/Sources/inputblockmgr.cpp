#include "inputblockmgr.hpp"
#include "exceptions/itemalreadyexistsincontainer.hpp"
#include "exceptions/iteminsertionfailure.hpp"

namespace TraceServer
{

    InputBlockMgr::InputBlockMgr()
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

        auto res = inputBlocks_.insert( std::make_pair(name, pBlock) );
        if ( !res.second )
        {
            throw Exceptions::ItemInsertionFailure("failure to add input block");
        }
    }


    void InputBlockMgr::startAll()
    {
        for (auto p : inputBlocks_)
        {
            p.second->start();
        }
    }


    void InputBlockMgr::stopAll()
    {
        for (auto p : inputBlocks_)
        {
            p.second->stop();
        }
    }
}
