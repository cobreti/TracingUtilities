#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "sources/TracesTableRow.hpp"
#include "sources/outputworkermgr.hpp"

namespace Ui {
class MainWindow;
}

class TracesTable;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    virtual void closeEvent(QCloseEvent*) override;

public slots:

    void onModuleNameTextChanged(const QString& text);
    void onTraceContentTextChanged();
    void onAddTrace(bool);
    void onTestBtn(bool);
    void onAddressEditingFinished();
    void onSetAddress(bool);
    void onAddressTextChanged(const QString& text);

protected:

    void connectSignalsSlots();
    void validateTraceContent();

protected:

    TracesTable         *pTable_;
    OutputWorkerMgr     workerMgr_;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
