#include "sources/TraceClientApp.hpp"
#include "MainWindow.h"

int main(int argc, char *argv[])
{
    int     ret{0};
    TraceClientApp      *pApp = new TraceClientApp(argc, argv);

    pApp->run();

    delete pApp;

    return ret;
}
