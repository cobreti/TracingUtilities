#ifndef RAWTRACE_HPP
#define RAWTRACE_HPP

#include <QtCore>
#include <memory>

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

        QDateTime timestamp() const noexcept { return timestamp_; }
        char* content() const noexcept { return content_; }

    protected:

        QDateTime       timestamp_;
        char*           content_;
        int             contentSize_;
    };

    using RawTracePtr = std::shared_ptr<RawTrace>;
}

#endif // RAWTRACE_HPP
