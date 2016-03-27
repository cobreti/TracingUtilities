#include "MonitorPanelWidget.hpp"
#include "ui_MonitorPanelWidget.h"
//#include "sources/application.hpp"

MonitorPanelWidget::MonitorPanelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorPanelWidget)
{
    ui->setupUi(this);

//    auto &server = Application::instance().server();
//    auto &msgBus = server.messageBus();
}

MonitorPanelWidget::~MonitorPanelWidget()
{
    delete ui;
}



void MonitorPanelWidget::closeEvent(QCloseEvent *)
{
    emit closing();
}
