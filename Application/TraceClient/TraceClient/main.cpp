#include "sources/TraceClientApp.hpp"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    int     ret{0};
    Application      *pApp = new Application(argc, argv);

    pApp->run();

    delete pApp;

    return ret;
}
