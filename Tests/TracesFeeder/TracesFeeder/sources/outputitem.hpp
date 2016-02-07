#ifndef OUTPUTITEM_HPP
#define OUTPUTITEM_HPP

#include <QtCore>


class OutputItem
{
public:
    OutputItem();
    OutputItem(const OutputItem& item);

    OutputItem& operator = (const OutputItem& item);

    const QString& moduleName() const { return moduleName_; }
    const QString& traceContent() const { return traceContent_; }

protected:

    void Swap( OutputItem& item ) noexcept;

protected:

    QString     moduleName_;
    QString     traceContent_;
};

#endif // OUTPUTITEM_HPP
