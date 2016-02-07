#include "application.hpp"
#include "mainwindow.hpp"


Application* Application::s_pInstance = nullptr;


Application& Application::instance()
{
    return *s_pInstance;
}


Application::Application(int argc, char *argv[]) :
    qApp_(argc, argv)
{
    s_pInstance = this;
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
