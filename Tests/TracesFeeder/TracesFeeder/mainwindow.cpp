#include "mainwindow.hpp"
#include "ui_mainwindow.h"

#include <qtcore>

#include "sources/outputitem.hpp"
#include "sources/tracestable.hpp"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->addButton_->setEnabled(false);
    ui->setButton_->setEnabled(false);

    pTable_ = new TracesTable(ui->tracesTableWidget_, workerMgr_);
    ui->tracesTableWidget_->setColumnWidth(0, 30);

    QRegExp             ipRegExp("\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}\\.\\d{1,3}");
    QRegExpValidator    *pIpValidator = new QRegExpValidator(ipRegExp);
    ui->serverNameInput_->setValidator(pIpValidator);

    connectSignalsSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::closeEvent(QCloseEvent *)
{
    workerMgr_.stopAll();
}


void MainWindow::onModuleNameTextChanged(const QString& text)
{
    validateTraceContent();
}


void MainWindow::onTraceContentTextChanged()
{
    validateTraceContent();
}


void MainWindow::onAddTrace(bool)
{
    QString         moduleName = ui->moduleNameInput_->text();
    QString         traceContent = ui->traceContentEdit_->document()->toPlainText();
    OutputItem      item(moduleName, traceContent, 10000);

    qDebug() << "trace content : " << traceContent;

    pTable_->addRow(item);
//    TableOutputItem tableItem(item, ui->tracesTableWidget_);

//    tableItems_.insert( std::make_pair(tableItem.row(), std::move(tableItem)) );
}


void MainWindow::onTestBtn(bool) {

//    auto iter = tableItems_.begin();
//    tableItems_.erase(iter);
}


void MainWindow::onAddressEditingFinished()
{

    ui->setButton_->setEnabled(true);

}

void MainWindow::onSetAddress(bool)
{
    QString     address = ui->serverNameInput_->text();

    qDebug() << "server address entered : " << address;

    workerMgr_.serverAddress() = QHostAddress(address);

    ui->setButton_->setEnabled(false);
}

void MainWindow::onAddressTextChanged(const QString &text)
{
    ui->setButton_->setEnabled(false);
}

void MainWindow::connectSignalsSlots()
{
    connect(    ui->moduleNameInput_, SIGNAL(textChanged(QString)),
                this, SLOT(onModuleNameTextChanged(QString)) );
    connect(    ui->traceContentEdit_, SIGNAL(textChanged()),
                this, SLOT(onTraceContentTextChanged()) );
    connect(    ui->addButton_, SIGNAL(clicked(bool)),
                this, SLOT(onAddTrace(bool)) );
    connect(    ui->testBtn_, SIGNAL(clicked(bool)),
                this, SLOT(onTestBtn(bool)) );
    connect(    ui->serverNameInput_, SIGNAL(editingFinished()),
                this, SLOT(onAddressEditingFinished()) );
    connect(    ui->serverNameInput_, SIGNAL(textChanged(QString)),
                this, SLOT(onAddressTextChanged(QString)) );
    connect(    ui->setButton_, SIGNAL(clicked(bool)),
                this, SLOT(onSetAddress(bool)) );
}


void MainWindow::validateTraceContent()
{
    QString moduleName = ui->moduleNameInput_->text();

    ui->addButton_->setEnabled( !moduleName.isEmpty() && !ui->traceContentEdit_->document()->isEmpty() );
}
