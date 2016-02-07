#ifndef OUTPUTITEMMGR_HPP
#define OUTPUTITEMMGR_HPP

#include "sources/outputitem.hpp"

#include <map>

class OutputItemMgr
{
public:
    OutputItemMgr();

    OutputItemMgr(const OutputItemMgr&) = delete;
    OutputItemMgr operator = (const OutputItemMgr&) = delete;

    void add( const OutputItem& item );
    std::pair<OutputItem, bool> get( const QString& moduleName );

protected:

    using OutputItemMap = std::map<QString, OutputItem>;

protected:

    OutputItemMap       items_;
};


#endif // OUTPUTITEMMGR_HPP
