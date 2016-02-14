#ifndef TracesTableRow_HPP
#define TracesTableRow_HPP

#include <qtcore>
#include <QTableWidget>
#include "sources/outputitem.hpp"
#include "sources/iconset.hpp"

class TracesTableRow
{
    friend class TracesTable;

public:

    using   RowIdT = OutputItem::OutputItemIdT;

    enum State
    {
        eState_Stopped,
        eState_Playing,
        eState_Stoping,
        eState_Starting
    };

    using   RowIconSet = IconSet<State>;

public:
    ~TracesTableRow();

    TracesTableRow(const TracesTableRow&) = delete;
    TracesTableRow& operator = (const TracesTableRow&) = delete;

    RowIdT id() const noexcept { return rowId_; }
    State state() const noexcept { return state_; }
    const OutputItem& item() const noexcept { return item_; }

    void setState(State state);

protected:

    TracesTableRow( int insertRow, const OutputItem& item, QTableWidget *pTableWidget, const RowIconSet& iconSet );

    void updateFromState();

protected:

    QTableWidget        *pTableWidget_;
    OutputItem          item_;

    QTableWidgetItem    *pModuleNameWidgetItem_;
    QTableWidgetItem    *pTraceContentWidgetItem_;
    QTableWidgetItem    *pStartStopWidgetItem_;

    RowIdT              rowId_;
    State               state_;

    const RowIconSet&   icons_;
};

#endif // TracesTableRow_HPP
