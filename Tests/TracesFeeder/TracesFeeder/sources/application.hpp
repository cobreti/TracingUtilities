#ifndef APPLICATION_HPP
#define APPLICATION_HPP

#include <QApplication>

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

    QApplication        qApp_;
};

#endif // APPLICATION_HPP
