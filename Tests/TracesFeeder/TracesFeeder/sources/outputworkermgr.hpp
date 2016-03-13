#ifndef OUTPUTWORKERMGR_HPP
#define OUTPUTWORKERMGR_HPP

#include <QtCore>
#include <QtNetwork>
#include <map>

#include "sources/outputitem.hpp"

class OutputWorker;

class OutputWorkerMgr : public QObject
{
    Q_OBJECT
public:
    explicit OutputWorkerMgr(QObject *parent = 0);

    void start( const OutputItem& item );
    void stop( const OutputItem::OutputItemIdT& itemId );
    void stopAll();

    QHostAddress& serverAddress() { return serverAddress_; }
    const QHostAddress& serverAddress() const { return serverAddress_; }

signals:

    void itemStarted(OutputItem::OutputItemIdT);
    void itemStopped(OutputItem::OutputItemIdT);
    void itemError(OutputItem::OutputItemIdT);

public slots:

    void onItemStarted(OutputItem::OutputItemIdT id);
    void onItemStopped(OutputItem::OutputItemIdT id);
    void onItemError(OutputItem::OutputItemIdT id);

protected:

    using OutputWorkerMapT = std::map<OutputItem::OutputItemIdT, OutputWorker*>;

protected:

    OutputWorkerMapT        workers_;
    QThreadPool             threadPool_;
    QHostAddress            serverAddress_;
    int                     port_;
};

#endif // OUTPUTWORKERMGR_HPP
