#ifndef TIMESTAMPTRACEFORMATER_HPP
#define TIMESTAMPTRACEFORMATER_HPP

namespace TraceServer
{
    class PrimaryStorage;

    class TimestampFormater
    {
    public:
        TimestampFormater(PrimaryStorage* pStorage);
        ~TimestampFormater();

        TimestampFormater(const TimestampFormater&) = delete;
        const TimestampFormater& operator = (const TimestampFormater &) = delete;

        void Format(char* content, int contentSize);

    protected:

        PrimaryStorage*     pPrimaryStorage_;
    };
}

#endif // TIMESTAMPTRACEFORMATER_HPP
