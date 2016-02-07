#ifndef INPUTBLOCKMGR_HPP
#define INPUTBLOCKMGR_HPP

#include <string>
#include <map>

#include "InputBlock.hpp"

namespace TraceServer
{
    class InputBlockMgr
    {
    public:
        InputBlockMgr();
        virtual ~InputBlockMgr();

        InputBlockMgr(const InputBlockMgr&) = delete;
        InputBlockMgr operator = (const InputBlockMgr&) = delete;

        void add( InputBlock* pBlock );

        void startAll();
        void stopAll();

    protected:

        using InputBlockMap = std::map<InputBlock::InputBlockNameT, InputBlock*>;

    protected:

        InputBlockMap       inputBlocks_;
    };
}

#endif // INPUTBLOCKMGR_HPP
