#ifndef OUTPUTITEM_HPP
#define OUTPUTITEM_HPP

#include <QtCore>
#include <atomic>


class OutputItem
{
public:

    using OutputItemIdT = int;

public:
    OutputItem();
    OutputItem(QString moduleName, QString traceContent, int intervalInMS);
    OutputItem(const OutputItem& item);

    OutputItem& operator = (const OutputItem& item);

    const QString& moduleName() const noexcept { return moduleName_; }
    const QString& traceContent() const noexcept { return traceContent_; }
    const OutputItemIdT& id() const noexcept { return id_; }

    // interval in milliseconds
    const int interval() const { return msInterval_; }

protected:

    void Swap( OutputItem& item ) noexcept;

protected:

    QString             moduleName_;
    QString             traceContent_;
    OutputItemIdT       id_;
    int                 msInterval_;

    static std::atomic<OutputItemIdT>        s_nextId_;
};

#endif // OUTPUTITEM_HPP
