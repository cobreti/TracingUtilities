#ifndef TABLEOUTPUTITEM_HPP
#define TABLEOUTPUTITEM_HPP

#include <qtcore>
#include <QTableWidget>
#include "sources/outputitem.hpp"


class TableOutputItem
{
public:
    TableOutputItem( const OutputItem& item, QTableWidget *pTableWidget );
    TableOutputItem( TableOutputItem&& tableItem );
    ~TableOutputItem();

    TableOutputItem& operator = (TableOutputItem&& tableItem);

    TableOutputItem(const TableOutputItem&) = delete;
    TableOutputItem& operator = (const TableOutputItem&) = delete;

    int row() const noexcept { return row_; }

protected:

    void swap( TableOutputItem& tableItem );

protected:

    QTableWidget        *pTableWidget_;
    OutputItem          item_;

    QTableWidgetItem    *pModuleNameWidgetItem_;
    QTableWidgetItem    *pTraceContentWidgetItem_;
    int                 row_;
};

#endif // TABLEOUTPUTITEM_HPP
