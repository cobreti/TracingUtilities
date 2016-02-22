#ifndef PRIMARYSTORAGE_HPP
#define PRIMARYSTORAGE_HPP

#include <qtCore>
#include <list>
#include <memory>

#include "rawtrace.hpp"

namespace TraceServer
{
    class PrimaryStorage
    {
    public:
        PrimaryStorage();
        ~PrimaryStorage();

        PrimaryStorage(const PrimaryStorage&) = delete;
        const PrimaryStorage& operator = (const PrimaryStorage&) = delete;

        void add( RawTracePtr pTrace );

    protected:

        using RawTraceList = std::list<RawTracePtr>;

    protected:

        RawTraceList        lists_[2];
        int                 activeList_;
    };
}

#endif // PRIMARYSTORAGE_HPP
