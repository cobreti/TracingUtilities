#include "TracesTableRow.hpp"

TracesTableRow::TracesTableRow( RowIdT rowId, const OutputItem& item, QTableWidget *pTableWidget) :
    pTableWidget_{pTableWidget},
    item_{item},
    rowId_{rowId}
{
    if ( nullptr == pTableWidget )
    {
        throw std::invalid_argument("table widget argument cannot be null");
    }

    pModuleNameWidgetItem_ = new QTableWidgetItem(item.moduleName());
    pTraceContentWidgetItem_ = new QTableWidgetItem(item.traceContent());
}


TracesTableRow::TracesTableRow( TracesTableRow&& tableItem ) :
    pTableWidget_{tableItem.pTableWidget_},
    item_{tableItem.item_},
    pModuleNameWidgetItem_{tableItem.pModuleNameWidgetItem_},
    pTraceContentWidgetItem_{tableItem.pTraceContentWidgetItem_}
{
    tableItem.pModuleNameWidgetItem_ = nullptr;
    tableItem.pTraceContentWidgetItem_ = nullptr;
    tableItem.pTableWidget_ = nullptr;
}


TracesTableRow::~TracesTableRow()
{
}


TracesTableRow& TracesTableRow::operator = (TracesTableRow&& tableItem)
{
    swap(tableItem);
    return *this;
}


void TracesTableRow::insertInTable(int row)
{
    pTableWidget_->setItem(row, 1, pModuleNameWidgetItem_);
    pTableWidget_->setItem(row, 2, pTraceContentWidgetItem_);
}

void TracesTableRow::swap( TracesTableRow& tableItem )
{
    std::swap( pModuleNameWidgetItem_, tableItem.pModuleNameWidgetItem_ );
    std::swap( pTraceContentWidgetItem_, tableItem.pTraceContentWidgetItem_ );
    std::swap( item_, tableItem.item_ );
    std::swap( pTableWidget_, tableItem.pTableWidget_ );
}
