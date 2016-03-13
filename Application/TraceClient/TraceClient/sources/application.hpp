#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include <QtCore>
#include "Server.hpp"
#include "monitorpanel.hpp"

enum
{
    kDefaultPort = 5000
};

class Application
{
public:

    static Application& instance();

public:
    Application(int argc, char *argv[]);

    Application(const Application&) = delete;
    Application operator = (const Application&) = delete;

    bool init();
    int run();
    void terminate();

    MonitorPanel& monitorPanel() { return monitorPanel_; }

protected:

    QApplication            qApp_;
    TraceServer::Server     server_;

    MonitorPanel            monitorPanel_;

private:

    static Application      *s_pInstance;
};

#endif // APPLICATION_HPP
