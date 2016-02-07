#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>
#include "Server.hpp"

class Application
{
public:
    Application(int argc, char *argv[]);

    Application(const Application&) = delete;
    Application operator = (const Application&) = delete;

    bool init();
    int run();
    void terminate();

protected:

    QApplication            qApp_;
    TraceServer::Server     server_;
};

#endif // APPLICATION_HPP
