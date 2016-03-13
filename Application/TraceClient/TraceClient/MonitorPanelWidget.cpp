#include "MonitorPanelWidget.hpp"
#include "ui_MonitorPanelWidget.h"

MonitorPanelWidget::MonitorPanelWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MonitorPanelWidget)
{
    ui->setupUi(this);
}

MonitorPanelWidget::~MonitorPanelWidget()
{
    delete ui;
}


void MonitorPanelWidget::closeEvent(QCloseEvent *)
{
    emit closing();
}
