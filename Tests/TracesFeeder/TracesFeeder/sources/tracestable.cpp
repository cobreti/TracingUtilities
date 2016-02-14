#include "tracestable.hpp"
#include <QtCore>
#include <QTableWidgetItem>
#include <cassert>

#include "sources/outputworkermgr.hpp"

TracesTable::TracesTable(QTableWidget* pTable, OutputWorkerMgr& workerMgr) :
    pTable_{pTable},
    workerMgr_{workerMgr}
{
    icons_.set( TracesTableRow::eState_Stopped, QIcon(":/TracesList/Icons/Play.png") );
    icons_.set( TracesTableRow::eState_Playing, QIcon(":/TracesList/Icons/Stop.png") );
    icons_.set( TracesTableRow::eState_Starting, QIcon(":/TracesList/Icons/Starting.png") );
    icons_.set( TracesTableRow::eState_Stoping, QIcon(":/TracesList/Icons/Stoping.png") );

    connect(    pTable_, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
                this, SLOT(onTableItemDoubleClicked(QTableWidgetItem*)) );
    connect(    &workerMgr, SIGNAL(itemStarted(OutputItem::OutputItemIdT)),
                this, SLOT(onItemStarted(OutputItem::OutputItemIdT)) );
    connect(    &workerMgr, SIGNAL(itemStopped(OutputItem::OutputItemIdT)),
                this, SLOT(onItemStopped(OutputItem::OutputItemIdT)) );
}


void TracesTable::addRow(const OutputItem &item)
{
    int rows = pTable_->rowCount();
    pTable_->setRowCount(rows+1);

    TracesTableRow      *pRow = new TracesTableRow(rows, item, pTable_, icons_);

    rows_.insert( std::make_pair(pRow->id(), pRow) );
}


void TracesTable::onTableItemDoubleClicked(QTableWidgetItem *item)
{
    QVariant rowIdItemData = item->data( Qt::ItemDataRole::UserRole );
    bool     resultOk;
    TracesTableRow::RowIdT rowId = rowIdItemData.toInt(&resultOk);

    assert(resultOk);

    auto pos = rows_.find(rowId);
    assert( pos != rows_.end() );

    TracesTableRow *pRow = pos->second;

    assert( pRow != nullptr );

    switch (pRow->state())
    {
        case TracesTableRow::eState_Stopped:
            pRow->setState(TracesTableRow::eState_Starting);
            workerMgr_.start(pRow->item());
            break;
        case TracesTableRow::eState_Playing:
            pRow->setState(TracesTableRow::eState_Stoping);
            workerMgr_.stop(pRow->item().id());
            break;
    }
}


void TracesTable::onItemStarted(OutputItem::OutputItemIdT id)
{
    auto pos = rows_.find(id);
    if ( pos == rows_.end() )
        return;

    pos->second->setState(TracesTableRow::eState_Playing);
}


void TracesTable::onItemStopped(OutputItem::OutputItemIdT id)
{
    auto pos = rows_.find(id);
    if ( pos == rows_.end() )
        return;

    pos->second->setState(TracesTableRow::eState_Stopped);
}
