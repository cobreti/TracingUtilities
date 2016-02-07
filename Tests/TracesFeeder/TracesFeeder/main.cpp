#include "sources/Application.hpp"

int main(int argc, char *argv[])
{
    Application app(argc, argv);

    int nRet{-1};

    if (app.init())
    {
        nRet = app.run();
        app.terminate();
    }

    return nRet;
}
