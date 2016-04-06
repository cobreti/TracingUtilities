#include "MonitorPanelWidget.hpp"
#include "ui_MonitorPanelWidget.h"
//#include "sources/application.hpp"

MonitorPanelWidget::MonitorPanelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorPanelWidget)
{
    ui->setupUi(this);

    ui->numberOfConnectionsEdit_->setText( QString::number(0) );

//    auto &server = Application::instance().server();
//    auto &msgBus = server.messageBus();
}

MonitorPanelWidget::~MonitorPanelWidget()
{
    delete ui;
}

void MonitorPanelWidget::setConnectionsCount(int count)
{
    ui->numberOfConnectionsEdit_->setText( QString::number(count) );
}

void MonitorPanelWidget::closeEvent(QCloseEvent *)
{
    emit closing();
}
