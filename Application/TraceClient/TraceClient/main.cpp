#include "sources/Application.hpp"

int main(int argc, char *argv[])
{
    Application     app(argc, argv);

    int     ret{-1};

    if ( app.init() )
    {
        ret = app.run();

        app.terminate();
    }

    return ret;
}
