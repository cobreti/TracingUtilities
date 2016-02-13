#include "tracestable.hpp"
#include <QtCore>
#include <QTableWidgetItem>
#include <cassert>

TracesTable::TracesTable(QTableWidget* pTable) :
    pTable_{pTable},
    nextId_{1}
{
    icons_.set( TracesTableRow::eState_Stopped, QIcon(":/TracesList/Icons/Play.png") );
    icons_.set( TracesTableRow::eState_Playing, QIcon(":/TracesList/Icons/Stop.png") );

    connect(    pTable_, SIGNAL(itemDoubleClicked(QTableWidgetItem*)),
                this, SLOT(onTableItemDoubleClicked(QTableWidgetItem*)) );
}


void TracesTable::addRow(const OutputItem &item)
{
    TracesTableRow::RowIdT id = nextId_;
    ++ nextId_;

    int rows = pTable_->rowCount();
    pTable_->setRowCount(rows+1);

    TracesTableRow      *pRow = new TracesTableRow(rows, id, item, pTable_, icons_);

    rows_.insert( std::make_pair(id, pRow) );
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
            pRow->setState(TracesTableRow::eState_Playing);
            break;
        case TracesTableRow::eState_Playing:
            pRow->setState(TracesTableRow::eState_Stopped);
            break;
    }
}
