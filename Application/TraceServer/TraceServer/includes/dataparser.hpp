#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP

#include "includes/timestamptraceformater.hpp"

namespace TraceServer
{
    class PrimaryStorage;

    class DataParser
    {
    public:
        DataParser( PrimaryStorage* pStorage, int bufferSize);
        ~DataParser();

        DataParser(const DataParser&) = delete;
        const DataParser& operator = (const DataParser&) = delete;

        void parse(char* pBuffer, int bufferSize);

    protected:

        char*           pBuffer_;
        char*           pWritePos_;
        char*           pBufferEnd_;
        const int       bufferSize_;

        TimestampFormater       timestampFormater_;

        int             count_;
    };
}

#endif // DATAPARSER_HPP
