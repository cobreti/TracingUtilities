#ifndef TIMESTAMPTRACEFORMATER_HPP
#define TIMESTAMPTRACEFORMATER_HPP

namespace TraceServer
{
    class TimestampFormater
    {
    public:
        TimestampFormater();
        ~TimestampFormater();

        TimestampFormater(const TimestampFormater&) = delete;
        const TimestampFormater& operator = (const TimestampFormater &) = delete;

        void Format(char* content, int contentSize);
    };
}

#endif // TIMESTAMPTRACEFORMATER_HPP
