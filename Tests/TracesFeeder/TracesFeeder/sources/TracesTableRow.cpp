#include <cassert>

#include "TracesTableRow.hpp"


TracesTableRow::TracesTableRow( int insertRow, const OutputItem& item, QTableWidget *pTableWidget, const RowIconSet& icons, const QIcon& errorIcon ) :
    pTableWidget_{pTableWidget},
    item_{item},
    pModuleNameWidgetItem_{},
    pFrequencyWidgetItem_{},
    pTraceContentWidgetItem_{},
    pStartStopWidgetItem_{},
    pErrorIndicatorWidgetItem{},
    rowId_{item.id()},
    state_{eState_Stopped},
    icons_{icons},
    errorIcon_{errorIcon}
{
    if ( nullptr == pTableWidget )
    {
        throw std::invalid_argument("table widget argument cannot be null");
    }

    if ( 0 == id() )
    {
        throw std::invalid_argument("invalid rowId value");
    }

    pModuleNameWidgetItem_ = new QTableWidgetItem(item.moduleName());
    pModuleNameWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );
    pModuleNameWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(id()) );

    pTraceContentWidgetItem_ = new QTableWidgetItem(item.traceContent());
    pTraceContentWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );
    pTraceContentWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(id()) );

    pStartStopWidgetItem_ = new QTableWidgetItem();
    pStartStopWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(id()) );
    pStartStopWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );

    pErrorIndicatorWidgetItem = new QTableWidgetItem();
    pErrorIndicatorWidgetItem->setData( Qt::ItemDataRole::UserRole, QVariant(id()) );
    pErrorIndicatorWidgetItem->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );

    pFrequencyWidgetItem_ = new QTableWidgetItem(QString().setNum(item.frequence()));
    pFrequencyWidgetItem_->setData( Qt::ItemDataRole::UserRole, QVariant(id()) );
    pFrequencyWidgetItem_->setFlags( Qt::ItemFlag::ItemIsEnabled | Qt::ItemFlag::ItemIsSelectable );

    pTableWidget_->setItem(insertRow, 0, pErrorIndicatorWidgetItem);
    pTableWidget_->setItem(insertRow, 1, pStartStopWidgetItem_);
    pTableWidget_->setItem(insertRow, 2, pModuleNameWidgetItem_);
    pTableWidget_->setItem(insertRow, 3, pFrequencyWidgetItem_);
    pTableWidget_->setItem(insertRow, 4, pTraceContentWidgetItem_);

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

void TracesTableRow::setError()
{
    pErrorIndicatorWidgetItem->setIcon( errorIcon_ );
}

void TracesTableRow::clearError()
{
    pErrorIndicatorWidgetItem->setIcon(QIcon());
}

void TracesTableRow::updateFromState()
{
    assert(pStartStopWidgetItem_ != nullptr);

    pStartStopWidgetItem_->setIcon( icons_.get(state_) );
}

