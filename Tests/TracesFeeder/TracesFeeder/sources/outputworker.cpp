#include "outputworker.hpp"
#include "sources/outputitem.hpp"


OutputWorker::OutputWorker(const OutputItem &outputItem) : QObject(nullptr),
    outputItem_{outputItem},
    stopRequested_{false}
{
    setAutoDelete(false);
}



void OutputWorker::run()
{
    emit started(id());

    while ( !stopRequested_)
    {
        QThread::sleep(2);
        qDebug() << "output worker running for item : " << outputItem_.moduleName();
    }

    emit terminated(id());
}


void OutputWorker::stop()
{
    stopRequested_ = true;
}

