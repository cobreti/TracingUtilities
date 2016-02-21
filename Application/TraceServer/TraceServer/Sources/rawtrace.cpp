#include "includes/rawtrace.hpp"


namespace TraceServer
{
    RawTrace::RawTrace() noexcept :
        content_{nullptr},
        contentSize_{0}
    {

    }


    RawTrace::RawTrace(const QDateTime &timestamp, char *content, int contentSize) :
        timestamp_{timestamp},
        contentSize_{contentSize}
    {
        content_ = new char[contentSize_];
        memcpy(content_, content, contentSize_);
    }


    RawTrace::~RawTrace()
    {
        delete[] content_;
    }
}
