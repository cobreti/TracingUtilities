#include "MonitorPanelWidget.hpp"
#include "ui_MonitorPanelWidget.h"
#include "sources/application.hpp"

MonitorPanelWidget::MonitorPanelWidget(QWidget *parent) :
    QWidget(parent),
    pMsgBusConnector{nullptr},
    ui(new Ui::MonitorPanelWidget)
{
    ui->setupUi(this);

    auto &server = Application::instance().server();
    auto &msgBus = server.messageBus();

    pMsgBusConnector = new TraceServer::MessageBusConnector(msgBus);
}

MonitorPanelWidget::~MonitorPanelWidget()
{
    delete ui;
    delete pMsgBusConnector;
}



void MonitorPanelWidget::closeEvent(QCloseEvent *)
{
    emit closing();
}
