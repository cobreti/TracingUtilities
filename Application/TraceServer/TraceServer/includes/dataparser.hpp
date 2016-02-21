#ifndef DATAPARSER_HPP
#define DATAPARSER_HPP

#include "includes/timestamptraceformater.hpp"

namespace TraceServer
{
    class DataParser
    {
    public:
        DataParser(int bufferSize);
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
    };
}

#endif // DATAPARSER_HPP