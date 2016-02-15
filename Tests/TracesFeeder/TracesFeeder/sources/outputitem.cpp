#include "sources/outputitem.hpp"

#include <algorithm>


std::atomic<OutputItem::OutputItemIdT> OutputItem::s_nextId_;

OutputItem::OutputItem() :
    id_(0)
{
}


OutputItem::OutputItem(QString moduleName, QString traceContent, int intervalInMS) :
    moduleName_{moduleName},
    traceContent_{traceContent},
    id_{ ++ s_nextId_ },
    msInterval_{intervalInMS}
{
}


OutputItem::OutputItem(const OutputItem &item) :
    moduleName_{item.moduleName_},
    traceContent_{item.traceContent_},
    id_{item.id_},
    msInterval_{item.msInterval_}
{
}


OutputItem& OutputItem::operator = (const OutputItem& item)
{
    OutputItem{item}.Swap(*this);

    return *this;
}


void OutputItem::Swap( OutputItem& item ) noexcept
{
    std::swap(moduleName_, item.moduleName_);
    std::swap(traceContent_, item.traceContent_);
    std::swap(id_, item.id_);
    std::swap(msInterval_, item.msInterval_);
}
