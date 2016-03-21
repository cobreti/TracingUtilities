#ifndef MESSAGEIDS_HPP
#define MESSAGEIDS_HPP

namespace TraceServer
{
    namespace Messages
    {
        using MessageID = unsigned int;

        namespace IDs
        {
            enum
            {
                kServerMessageBase                          = 0x0000,

                kConnectionsCountChanged                    =   kServerMessageBase + 1
            };
        }
    }
}

#endif // MESSAGEIDS_HPP
