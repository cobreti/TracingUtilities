#include "outputItemMgr.hpp"

OutputItemMgr::OutputItemMgr()
{
}


void OutputItemMgr::add(const OutputItem& item)
{
    items_.insert( std::make_pair(item.moduleName(), item) );
}


std::pair<OutputItem, bool> OutputItemMgr::get( const QString& moduleName )
{
    auto pos = items_.find(moduleName);

    if ( pos == items_.end() )
    {
        return std::make_pair(OutputItem(), false);
    }

    return std::make_pair(pos->second, true);
}


