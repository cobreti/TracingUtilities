#ifndef MONITORPANELWIDGET_HPP
#define MONITORPANELWIDGET_HPP

#include <QWidget>
#include "MessageBus.hpp"


namespace Ui {
class MonitorPanelWidget;
}

class MonitorPanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorPanelWidget(QWidget *parent = 0);
    ~MonitorPanelWidget();

    void setConnectionsCount(int count);

signals:

    void closing();

protected slots:


protected:

    virtual void closeEvent(QCloseEvent *) override;

private:
    Ui::MonitorPanelWidget *ui;
};

#endif // MONITORPANELWIDGET_HPP
