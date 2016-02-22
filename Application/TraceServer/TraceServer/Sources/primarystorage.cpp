#include "includes/primarystorage.hpp"

namespace TraceServer
{
    PrimaryStorage::PrimaryStorage() :
        activeList_{0}
    {
    }


    PrimaryStorage::~PrimaryStorage()
    {
    }


    void PrimaryStorage::add(RawTracePtr pTrace)
    {
        lists_[activeList_].push_back(pTrace);

        qDebug() << "adding trace : " << pTrace->timestamp() << " --> " << pTrace->content();
        qDebug() << "new trace count : " << lists_[activeList_].size();
    }
}

