#include "tableoutputitem.hpp"

TableOutputItem::TableOutputItem(const OutputItem& item, QTableWidget *pTableWidget) :
    pTableWidget_{pTableWidget},
    item_{item}
{
    if ( nullptr == pTableWidget )
    {
        throw std::invalid_argument("table widget argument cannot be null");
    }

    row_ = pTableWidget->rowCount() + 1;

    pModuleNameWidgetItem_ = new QTableWidgetItem(item.moduleName());
    pTraceContentWidgetItem_ = new QTableWidgetItem(item.traceContent());

    pTableWidget_->setRowCount(row_);

    pTableWidget_->setItem(row_-1, 1, pModuleNameWidgetItem_);
    pTableWidget_->setItem(row_-1, 2, pTraceContentWidgetItem_);
}


TableOutputItem::TableOutputItem( TableOutputItem&& tableItem ) :
    pTableWidget_{tableItem.pTableWidget_},
    item_{tableItem.item_},
    pModuleNameWidgetItem_{tableItem.pModuleNameWidgetItem_},
    pTraceContentWidgetItem_{tableItem.pTraceContentWidgetItem_},
    row_{tableItem.row_}
{
    tableItem.pModuleNameWidgetItem_ = nullptr;
    tableItem.pTraceContentWidgetItem_ = nullptr;
    tableItem.pTableWidget_ = nullptr;
}


TableOutputItem::~TableOutputItem()
{
    if (pTableWidget_ && pModuleNameWidgetItem_)
    {
        auto r = pModuleNameWidgetItem_->row();

        qDebug() << "item row = " << r << " vs saved row " << row_-1;

        pTableWidget_->removeRow(r);
    }
}


TableOutputItem& TableOutputItem::operator = (TableOutputItem&& tableItem)
{
    swap(tableItem);
    return *this;
}


void TableOutputItem::swap( TableOutputItem& tableItem )
{
    std::swap( pModuleNameWidgetItem_, tableItem.pModuleNameWidgetItem_ );
    std::swap( pTraceContentWidgetItem_, tableItem.pTraceContentWidgetItem_ );
    std::swap( row_, tableItem.row_ );
    std::swap( item_, tableItem.item_ );
    std::swap( pTableWidget_, tableItem.pTableWidget_ );
}
