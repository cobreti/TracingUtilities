#ifndef TracesTableRow_HPP
#define TracesTableRow_HPP

#include <qtcore>
#include <QTableWidget>
#include "sources/outputitem.hpp"


class TracesTableRow
{
    friend class TracesTable;

public:

    using   RowIdT = int;

public:
    TracesTableRow( TracesTableRow&& tableItem );
    ~TracesTableRow();

    TracesTableRow& operator = (TracesTableRow&& tableItem);

    TracesTableRow(const TracesTableRow&) = delete;
    TracesTableRow& operator = (const TracesTableRow&) = delete;

    RowIdT rowId() const { return rowId_; }

protected:

    TracesTableRow( RowIdT id, const OutputItem& item, QTableWidget *pTableWidget );

    void insertInTable(int row);
    void swap( TracesTableRow& tableItem );

protected:

    QTableWidget        *pTableWidget_;
    OutputItem          item_;

    QTableWidgetItem    *pModuleNameWidgetItem_;
    QTableWidgetItem    *pTraceContentWidgetItem_;

    RowIdT              rowId_;
};

#endif // TracesTableRow_HPP
