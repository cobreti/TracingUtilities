#include "includes/timestamptraceformater.hpp"

#include <QtCore>
#include <cassert>
#include <string>

#include "includes/primarystorage.hpp"

namespace TraceServer
{
    TimestampFormater::TimestampFormater(PrimaryStorage* pStorage) :
        pPrimaryStorage_{pStorage}
    {

    }


    TimestampFormater::~TimestampFormater()
    {

    }


    void TimestampFormater::Format(char *content, int contentSize)
    {
        assert( strlen(content) == contentSize );

        QDateTime timestamp = QDateTime::currentDateTime();
        RawTracePtr pTrace(new RawTrace(timestamp, content, contentSize));

        pPrimaryStorage_->add(pTrace);
    }
}
