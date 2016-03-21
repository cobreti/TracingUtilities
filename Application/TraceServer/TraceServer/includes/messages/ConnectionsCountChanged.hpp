#ifndef CONNECTIONSCOUNTCHANGED_HPP
#define CONNECTIONSCOUNTCHANGED_HPP

#include "messages/Message.hpp"

namespace TraceServer
{
    namespace Messages
    {
        class ConnectionsCountChanged : public Message
        {
        public:
            ConnectionsCountChanged(int count);
            ConnectionsCountChanged(const ConnectionsCountChanged &other);

            int count() const { return connectionsCount_; }

            virtual Message* cloneToPtr() const;

        protected:

            int     connectionsCount_;
        };
    }
}

#endif // CONNECTIONSCOUNTCHANGED_HPP
