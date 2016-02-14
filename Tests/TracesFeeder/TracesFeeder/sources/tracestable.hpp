#ifndef TRACESTABLE_HPP
#define TRACESTABLE_HPP

#include <qtcore>
#include <QTableWidget>
#include <map>
#include "sources/TracesTableRow.hpp"


class OutputWorkerMgr;

class TracesTable : QObject
{
    Q_OBJECT

public:
    TracesTable(QTableWidget* pTable, OutputWorkerMgr& workerMgr);

    TracesTable(const TracesTable&) = delete;
    TracesTable& operator = (const TracesTable&) = delete;

    void addRow( const OutputItem& item );

public slots:

    void onTableItemDoubleClicked( QTableWidgetItem* item );
    void onItemStarted( OutputItem::OutputItemIdT id );
    void onItemStopped( OutputItem::OutputItemIdT id );

protected:

    using TableRowMap = std::map<TracesTableRow::RowIdT, TracesTableRow*>;

protected:

    QTableWidget                        *pTable_;
    TableRowMap                         rows_;

    TracesTableRow::RowIconSet          icons_;

    OutputWorkerMgr                     &workerMgr_;
};

#endif // TRACESTABLE_HPP
