#ifndef MSGBUCKET_HPP
#define MSGBUCKET_HPP

namespace TraceServer
{
    template <class TMSG>
    class MsgBucket
    {
    public:
        template <typename... Targs>
        MsgBucket(Targs... Fargs)
        {
            pMsg_ = new TMSG(Fargs...);
        }

    protected:

        TMSG        *pMsg_;
    };
}

#endif // MSGBUCKET_HPP
