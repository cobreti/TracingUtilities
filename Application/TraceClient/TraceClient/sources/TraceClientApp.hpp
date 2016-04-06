#ifndef TRACECLIENTAPP_HPP
#define TRACECLIENTAPP_HPP

#include <QtCore>
#include <QApplication>

class MainWindow;
class MonitorPanel;

namespace TraceServer
{
    class Server;
}


class TraceClientApp : public QObject
{
    Q_OBJECT

public:

    static TraceClientApp& instance();

public:
    TraceClientApp(int argc, char *argv[]);
    virtual ~TraceClientApp();

    void run();

    constexpr int tcpPort() const noexcept { return 5000; }

    TraceServer::Server& server() const { return *pServer_; }

    MonitorPanel& monitorPanel();

protected slots:

    void onStart();

protected:

    QApplication            qApp_;
    QTimer                  startTimer_;
    TraceServer::Server*    pServer_;

    MainWindow              *pMainWindow_;
    MonitorPanel            *pMonitorPanel_;

private:

    static TraceClientApp*     s_pInstance;
};

#endif // TRACECLIENTAPP_HPP
