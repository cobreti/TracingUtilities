#include "tracestable.hpp"


TracesTable::TracesTable(QTableWidget* pTable) :
    pTable_{pTable},
    nextId_{1}
{

}


void TracesTable::addRow(const OutputItem &item)
{
    TracesTableRow::RowIdT id = nextId_;
    ++ nextId_;

    TracesTableRow      row(id, item, pTable_);

    auto rows = pTable_->rowCount();
    pTable_->setRowCount(rows+1);

    row.insertInTable(rows);
    rows_.insert( std::make_pair(id, std::move(row)) );
}
