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
    OutputItem(QString moduleName, QString traceContent, int frequence);
    OutputItem(const OutputItem& item);

    OutputItem& operator = (const OutputItem& item);

    const QString& moduleName() const noexcept { return moduleName_; }
    const QString& traceContent() const noexcept { return traceContent_; }
    const OutputItemIdT& id() const noexcept { return id_; }

    // interval in milliseconds
    const int frequence() const { return frequence_; }

protected:

    void Swap( OutputItem& item ) noexcept;

protected:

    QString             moduleName_;
    QString             traceContent_;
    OutputItemIdT       id_;
    int                 frequence_; // frequence per sec

    static std::atomic<OutputItemIdT>        s_nextId_;
};

#endif // OUTPUTITEM_HPP
