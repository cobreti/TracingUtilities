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
    ui->connectButton_->setEnabled(false);

    pTable_ = new TracesTable(ui->tracesTableWidget_);
    ui->tracesTableWidget_->setColumnWidth(0, 30);

    connectSignalsSlots();
}

MainWindow::~MainWindow()
{
    delete ui;
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
    OutputItem      item(moduleName, traceContent);

    qDebug() << "trace content : " << traceContent;

    pTable_->addRow(item);
//    TableOutputItem tableItem(item, ui->tracesTableWidget_);

//    tableItems_.insert( std::make_pair(tableItem.row(), std::move(tableItem)) );
}


void MainWindow::onTestBtn(bool) {

//    auto iter = tableItems_.begin();
//    tableItems_.erase(iter);
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
}


void MainWindow::validateTraceContent()
{
    QString moduleName = ui->moduleNameInput_->text();

    ui->addButton_->setEnabled( !moduleName.isEmpty() && !ui->traceContentEdit_->document()->isEmpty() );
}
