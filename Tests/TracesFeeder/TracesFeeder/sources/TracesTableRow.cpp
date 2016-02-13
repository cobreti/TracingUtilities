#include <cassert>

#include "TracesTableRow.hpp"


TracesTableRow::TracesTableRow( int insertRow, RowIdT rowId, const OutputItem& item, QTableWidget *pTableWidget, const RowIconSet& icons ) :
    pTableWidget_{pTableWidget},
    item_{item},
    rowId_{rowId},
    state_{eState_Stopped},
    icons_{icons}
{
    if ( nullptr == pTableWidget )
    {
        throw std::invalid_argument("table widget argument cannot be null");
    }

    if ( 0 == rowId )
    {
        throw std::invalid_argument("invalid rowId value");
    }

    pModuleNameWidgetItem_ = new QTableWidgetItem(item.moduleName());
    pModuleNameWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );
    pModuleNameWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(rowId) );

    pTraceContentWidgetItem_ = new QTableWidgetItem(item.traceContent());
    pTraceContentWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );
    pTraceContentWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(rowId) );

    pStartStopWidgetItem_ = new QTableWidgetItem();
    pStartStopWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(rowId) );
    pStartStopWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );

    pTableWidget_->setItem(insertRow, 0, pStartStopWidgetItem_);
    pTableWidget_->setItem(insertRow, 1, pModuleNameWidgetItem_);
    pTableWidget_->setItem(insertRow, 2, pTraceContentWidgetItem_);

    updateFromState();
}



TracesTableRow::~TracesTableRow()
{
}



void TracesTableRow::setState(State state)
{
    if (state != state_) {
        state_ = state;
        updateFromState();
    }
}


void TracesTableRow::updateFromState()
{
    assert(pStartStopWidgetItem_ != nullptr);

    pStartStopWidgetItem_->setIcon( icons_.get(state_) );
}

