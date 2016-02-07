#include "sources/outputitem.hpp"

#include <algorithm>


OutputItem::OutputItem()
{
}


OutputItem::OutputItem(QString moduleName, QString traceContent) :
    moduleName_{moduleName},
    traceContent_{traceContent}
{
}


OutputItem::OutputItem(const OutputItem &item) :
    moduleName_{item.moduleName_},
    traceContent_{item.traceContent_}
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
}
