#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "networkUtility.hpp"
#include "sources/TraceClientApp.hpp"
#include "sources/MonitorPanel.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hostAddressField_->setText( NetworkUtility().getHostAddress().toString() );
    ui->portField_->setText( QString().setNum( TraceClientApp::instance().tcpPort() ) );

    connect(    ui->showMonitorPanelBtn, SIGNAL(clicked(bool)),
                this, SLOT(onShowMonitorPanel(bool)) );
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::onShowMonitorPanel(bool)
{
    QPoint pos = window()->frameGeometry().topLeft();

    pos.rx() += 50;
    pos.ry() += 50;

    TraceClientApp::instance().monitorPanel().show(pos);
}
