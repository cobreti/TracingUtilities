#include "application.hpp"
#include "mainwindow.hpp"


Application::Application(int argc, char *argv[]) :
    qApp_(argc, argv)
{
}


bool Application::init() {


    return true;
}


int Application::run() {

    MainWindow w;
    w.show();

    return qApp_.exec();
}


void Application::terminate()
{

}
