#include "mainwindow.hpp"
#include "ui_mainwindow.h"
#include "networkUtility.hpp"
#include "sources/Application.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->hostAddressField_->setText( NetworkUtility().getHostAddress().toString() );
    ui->portField_->setText( QString().setNum(kDefaultPort) );
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

    Application::instance().monitorPanel().show(pos);
//    Application::instance().showMonitorPanel(pos);
}
