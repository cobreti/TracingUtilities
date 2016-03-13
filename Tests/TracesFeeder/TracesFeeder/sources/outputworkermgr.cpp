#include "outputworkermgr.hpp"
#include "outputworker.hpp"

OutputWorkerMgr::OutputWorkerMgr(QObject *parent) : QObject(parent),
    port_{5000}
{

}


void OutputWorkerMgr::start(const OutputItem &item)
{
    if ( workers_.count(item.id()) > 0 )
        throw std::runtime_error("outputitem already present in a worker");

    OutputWorker*       pWorker = new OutputWorker(item, serverAddress_, port_);
    workers_.insert( std::make_pair(pWorker->id(), pWorker) );

    connect(    pWorker, SIGNAL(started(OutputItem::OutputItemIdT)),
                this, SLOT(onItemStarted(OutputItem::OutputItemIdT)) );
    connect(    pWorker, SIGNAL(terminated(OutputItem::OutputItemIdT)),
                this, SLOT(onItemStopped(OutputItem::OutputItemIdT)) );
    connect(    pWorker, SIGNAL(error(OutputItem::OutputItemIdT)),
                this, SLOT(onItemError(OutputItem::OutputItemIdT)) );

    threadPool_.start( static_cast<QRunnable*>(pWorker) );
}


void OutputWorkerMgr::stop( const OutputItem::OutputItemIdT& itemId )
{
    auto workerPos = workers_.find(itemId);
    if ( workerPos == workers_.end() )
        return;

    workerPos->second->stop();
}


void OutputWorkerMgr::stopAll()
{
    for ( auto p : workers_ )
    {
        p.second->stop();
    }
}


void OutputWorkerMgr::onItemStarted(OutputItem::OutputItemIdT id)
{
    qDebug() << "onItemStarted : " << id;

    emit itemStarted(id);
}


void OutputWorkerMgr::onItemStopped(OutputItem::OutputItemIdT id)
{
    qDebug() << "onItemStopped : " << id;

    emit itemStopped(id);

    auto pos = workers_.find(id);
    if ( pos == workers_.end() )
        return;

    OutputWorker* pWorker = pos->second;
    workers_.erase(pos);
    delete pWorker;
}


void OutputWorkerMgr::onItemError(OutputItem::OutputItemIdT id)
{
    emit itemError(id);
}

