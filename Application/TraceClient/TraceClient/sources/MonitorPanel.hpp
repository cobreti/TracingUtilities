#ifndef MONITORPANEL_HPP
#define MONITORPANEL_HPP

#include <QtCore>
#include "MonitorPanelWidget.hpp"

class MonitorPanel : public QObject
{
    Q_OBJECT

public:
    MonitorPanel();

    void show(QPoint pos);

protected slots:

    void onPanelClosed();

protected:

    MonitorPanelWidget      *pWidget_;
};

#endif // MONITORPANEL_HPP
