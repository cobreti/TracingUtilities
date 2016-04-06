#include "MonitorPanel.hpp"
#include "TraceClientApp.hpp"

MonitorPanel::MonitorPanel() : QObject(),
    pWidget_{nullptr},
    pMsgHandlers_{nullptr}
{

    auto &server = TraceClientApp::instance().server();

    pMsgHandlers_ = new MonitorPanelMsgHandler(*this, server.messageBus());

    connect(    pMsgHandlers_,  SIGNAL(connectionsCountChanged(int)),
                this,           SLOT(onConnectionsCountChanged(int)) );
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


void MonitorPanel::onConnectionsCountChanged(int count)
{
    if ( pWidget_ )
        pWidget_->setConnectionsCount(count);
}
