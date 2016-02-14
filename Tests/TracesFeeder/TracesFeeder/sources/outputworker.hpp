#ifndef OUTPUTWORKER_HPP
#define OUTPUTWORKER_HPP

#include <QtCore>
#include <atomic>

#include "sources/OutputItem.hpp"


class OutputWorker : public QObject, public QRunnable
{
    Q_OBJECT
public:
    explicit OutputWorker(const OutputItem &outputItem);

    const OutputItem::OutputItemIdT& id() const noexcept { return outputItem_.id(); }

    virtual void run() override;

    void stop();

signals:

    void started(OutputItem::OutputItemIdT);
    void terminated(OutputItem::OutputItemIdT);

public slots:

protected:

    const OutputItem    &outputItem_;
    std::atomic<bool>   stopRequested_;
};

#endif // OUTPUTWORKER_HPP
