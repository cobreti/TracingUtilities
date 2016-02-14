#include "application.hpp"
#include "mainwindow.hpp"
#include "sources/outputitem.hpp"

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

    qRegisterMetaType<OutputItem::OutputItemIdT>("OutputItem::OutputItemIdT");

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
