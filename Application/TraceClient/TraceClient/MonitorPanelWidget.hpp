#ifndef MONITORPANELWIDGET_HPP
#define MONITORPANELWIDGET_HPP

#include <QWidget>

namespace Ui {
class MonitorPanelWidget;
}

class MonitorPanelWidget : public QWidget
{
    Q_OBJECT

public:
    explicit MonitorPanelWidget(QWidget *parent = 0);
    ~MonitorPanelWidget();

signals:

    void closing();

protected:

    virtual void closeEvent(QCloseEvent *) override;

private:
    Ui::MonitorPanelWidget *ui;
};

#endif // MONITORPANELWIDGET_HPP
