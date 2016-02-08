#ifndef TRACESTABLE_HPP
#define TRACESTABLE_HPP

#include <qtcore>
#include <QTableWidget>
#include <map>
#include "sources/TracesTableRow.hpp"

class TracesTable : QObject
{
    Q_OBJECT

public:
    TracesTable(QTableWidget* pTable);

    TracesTable(const TracesTable&) = delete;
    TracesTable& operator = (const TracesTable&) = delete;

    void addRow( const OutputItem& item );

protected:

    using TableRowMap = std::map<TracesTableRow::RowIdT, TracesTableRow>;

protected:

    QTableWidget                *pTable_;
    TableRowMap                 rows_;

    TracesTableRow::RowIdT      nextId_;
};

#endif // TRACESTABLE_HPP
