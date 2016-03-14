#include "messages/ConnectionsCountChanged.hpp"

namespace TraceServer
{
    namespace Messages
    {
        ConnectionsCountChanged::ConnectionsCountChanged(int count) :
            connectionsCount_{count}
        {

        }
    }
}
