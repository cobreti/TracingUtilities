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
