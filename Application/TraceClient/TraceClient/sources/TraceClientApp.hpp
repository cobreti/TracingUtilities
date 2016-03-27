#ifndef TRACECLIENTAPP_HPP
#define TRACECLIENTAPP_HPP

#include <QtCore>
#include <QApplication>

class MainWindow;

namespace TraceServer
{
    class Server;
}


class TraceClientApp : public QObject
{
    Q_OBJECT

public:
    TraceClientApp(int argc, char *argv[]);
    virtual ~TraceClientApp();

    void run();

protected slots:

    void onStart();

protected:

    QApplication            qApp_;
    QTimer                  startTimer_;
    TraceServer::Server*    pServer_;

    MainWindow              *pMainWindow_;
};

#endif // TRACECLIENTAPP_HPP
