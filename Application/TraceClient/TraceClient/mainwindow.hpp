#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>

#include "server.hpp"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

public slots:

    void onShowMonitorPanel(bool);

private:
    Ui::MainWindow *ui;

    TraceServer::Server     server_;
};

#endif // MAINWINDOW_HPP
