#include "includes/timestamptraceformater.hpp"

#include <QtCore>
#include <cassert>
#include <string>

namespace TraceServer
{
    TimestampFormater::TimestampFormater()
    {

    }


    TimestampFormater::~TimestampFormater()
    {

    }


    void TimestampFormater::Format(char *content, int contentSize)
    {
        assert( strlen(content) == contentSize );

        QDateTime timestamp = QDateTime::currentDateTime();

        qDebug() << timestamp << " --> " << content;
    }
}
