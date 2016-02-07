#ifndef MAINWINDOW_HPP
#define MAINWINDOW_HPP

#include <QMainWindow>
#include "sources/tableoutputitem.hpp"

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

    void onModuleNameTextChanged(const QString& text);
    void onTraceContentTextChanged();
    void onAddTrace(bool);
    void onTestBtn(bool);

protected:

    void connectSignalsSlots();
    void validateTraceContent();

protected:

    using TableOutputItemMap = std::map<int, TableOutputItem>;

protected:

    TableOutputItemMap      tableItems_;

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_HPP
