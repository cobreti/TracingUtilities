#ifndef MONITORPANEL_HPP
#define MONITORPANEL_HPP

#include <QtCore>
#include "MonitorPanelWidget.hpp"
#include "MonitorPanelMsgHandler.hpp"


class MonitorPanel : public QObject
{
    Q_OBJECT

public:
    MonitorPanel();

    void show(QPoint pos);

protected slots:

    void onPanelClosed();
    void onConnectionsCountChanged(int count);

protected:

    MonitorPanelWidget      *pWidget_;
    MonitorPanelMsgHandler  *pMsgHandlers_;
};

#endif // MONITORPANEL_HPP
