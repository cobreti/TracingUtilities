#include "outputworker.hpp"
#include "sources/outputitem.hpp"


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
    bytes.append("\0");

    while ( connected && !stopRequested_)
    {
        pSocket_->write(bytes);
        pSocket_->flush();
        qDebug() << "output worker running for item : " << outputItem_.moduleName();

        QThread::msleep(outputItem_.interval());
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

