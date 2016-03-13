#include "MonitorPanel.hpp"

MonitorPanel::MonitorPanel() : QObject(),
    pWidget_{nullptr}
{

}


void MonitorPanel::show(QPoint pos)
{
    if ( pWidget_ )
    {
        pWidget_->window()->raise();
        pWidget_->activateWindow();
//        pMonitorPanel_->show();
        return;
    }

    pWidget_ = new MonitorPanelWidget();
    pWidget_->show();
    pWidget_->window()->move(pos);

    connect(    pWidget_, SIGNAL(closing()),
                this, SLOT(onPanelClosed()) );
}


void MonitorPanel::onPanelClosed()
{
    delete pWidget_;
    pWidget_ = nullptr;
}
