#ifndef RAWTRACE_HPP
#define RAWTRACE_HPP

#include <QtCore>

namespace TraceServer
{
    class RawTrace
    {
    public:
        RawTrace() noexcept;
        RawTrace(const QDateTime& timestamp, char* content, int contentSize);
        ~RawTrace();

        RawTrace(const RawTrace&) = delete;
        const RawTrace& operator = (const RawTrace&) = delete;

    protected:

        QDateTime       timestamp_;
        char*           content_;
        int             contentSize_;
    };
}

#endif // RAWTRACE_HPP
