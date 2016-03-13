#ifndef INPUTBLOCKMGR_HPP
#define INPUTBLOCKMGR_HPP

#include <string>
#include <map>
#include <algorithm>

#include "InputBlock.hpp"

namespace TraceServer
{
    class MessageBus;
    class ConnectionsMonitor;

    class InputBlockMgr
    {
    public:
        InputBlockMgr(MessageBus &msgBus);
        virtual ~InputBlockMgr();

        InputBlockMgr(const InputBlockMgr&) = delete;
        InputBlockMgr operator = (const InputBlockMgr&) = delete;

        void add( InputBlock* pBlock );

        void startAll();
        void stopAll();

    protected:

        class InputBlockEntry
        {
        public:
            InputBlockEntry(InputBlock *pBlock, ConnectionsMonitor *pMonitor) : pInputBlock_{pBlock}, pMonitor_{pMonitor} {}
            InputBlockEntry(const InputBlockEntry& entry) : pInputBlock_{entry.pInputBlock_}, pMonitor_{entry.pMonitor_} {}

            const InputBlockEntry& operator = (const InputBlockEntry &entry)
            {
                InputBlockEntry(entry).Swap(*this);

                return *this;
            }

            InputBlock* inputBlock() const { return pInputBlock_; }
            ConnectionsMonitor* monitor() const { return pMonitor_; }

        protected:

            void Swap(InputBlockEntry &entry)
            {
                std::swap(pInputBlock_, entry.pInputBlock_);
                std::swap(pMonitor_, entry.pMonitor_);
            }

        protected:
            InputBlock              *pInputBlock_;
            ConnectionsMonitor      *pMonitor_;
        };

        using InputBlockMap = std::map<QString, InputBlockEntry>;

    protected:

        InputBlockMap       inputBlocks_;
        MessageBus          &msgBus_;
    };
}

#endif // INPUTBLOCKMGR_HPP
