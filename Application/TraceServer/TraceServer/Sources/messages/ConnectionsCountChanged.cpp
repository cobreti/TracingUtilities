#include "messages/ConnectionsCountChanged.hpp"

namespace TraceServer
{
    namespace Messages
    {
        ConnectionsCountChanged::ConnectionsCountChanged(int count) :
            Message(IDs::kConnectionsCountChanged),
            connectionsCount_{count}
        {

        }

        ConnectionsCountChanged::ConnectionsCountChanged(const ConnectionsCountChanged &other) :
            Message(*this),
            connectionsCount_{other.connectionsCount_}
        {

        }
    }
}
