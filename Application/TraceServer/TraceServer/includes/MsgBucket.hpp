#ifndef MSGBUCKET_HPP
#define MSGBUCKET_HPP

#include "messages/Message.hpp"

namespace TraceServer
{
    class MsgBucket
    {
    public:
        virtual Messages::Message* detach() const = 0;
    };

    template <class TMSG>
    class TMsgBucket : public MsgBucket
    {
    public:
        template <typename... Targs>
        TMsgBucket(Targs... Fargs)
        {
            pMsg_ = new TMSG(Fargs...);
        }

        ~TMsgBucket()
        {
            delete pMsg_;
        }

        Messages::Message* detach() const
        {
            auto *pMsg = pMsg_;
            pMsg_ = nullptr;
            return pMsg;
        }

    protected:

        mutable TMSG        *pMsg_;
    };
}

#endif // MSGBUCKET_HPP
