#include "outputworker.hpp"
#include "sources/outputitem.hpp"

#include <chrono>


OutputWorker::OutputWorker(const OutputItem &outputItem,  const QHostAddress& serverAddress, int port) : QObject(nullptr),
    outputItem_{outputItem},
    stopRequested_{false},
    serverAddress_{serverAddress},
    port_{port},
    pSocket_{nullptr}
{
    setAutoDelete(false);
}


void OutputWorker::run()
{
    emit started(id());

    pSocket_ = new QTcpSocket();
    pSocket_->connectToHost(serverAddress_, port_);

    bool connected = pSocket_->waitForConnected();
    if ( !connected )
    {
        qWarning() << "unable to connect to host : " << serverAddress_ << " on port " << port_;
    }

    QString line = "{ " + outputItem_.moduleName() + " } / " + outputItem_.traceContent();
    QByteArray bytes = line.toLocal8Bit();
    bytes.append('\0');

    while ( connected && !stopRequested_)
    {
        int count = 0;
        auto timeBefore = std::chrono::high_resolution_clock::now();

        while ( count < outputItem_.frequence() )
        {
            pSocket_->write(bytes);
            pSocket_->flush();
            ++ count;
        }

        auto timeAfter = std::chrono::high_resolution_clock::now();

        std::chrono::duration<double> timeSpan = std::chrono::duration_cast<std::chrono::duration<double>>(timeAfter - timeBefore);
        int sleepTime = (1-timeSpan.count()) * 1000;

        qDebug() << "time to execute : " << timeSpan.count() << " -- remaining time to sleep : " << sleepTime << " --- count = " << count;

        if ( sleepTime > 0.0 )
        {
            QThread::msleep(sleepTime);
        }

        if ( sleepTime < 0.0 )
        {
            // error
            emit error(id());
            break;
        }
    }

    if ( connected )
    {
        pSocket_->close();
    }

    delete pSocket_;
    pSocket_ = nullptr;

    emit terminated(id());
}


void OutputWorker::stop()
{
    stopRequested_ = true;
}

