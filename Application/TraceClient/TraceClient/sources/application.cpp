#include "application.hpp"
#include "mainwindow.hpp"
#include "InputBlock.hpp"

Application::Application(int argc, char *argv[]) :
    qApp_(argc, argv)
{

}


bool Application::init()
{
    TraceServer::InputBlock *pBlock = nullptr;

    try
    {
        pBlock = new TraceServer::InputBlock("default", 5000);

        server_.inputBlocks().add(pBlock);

        server_.inputBlocks().startAll();
    }
    catch (std::exception& err)
    {
        delete pBlock;

        qCritical() << "error when creating input block : " << err.what();
    }

    return true;
}


int Application::run()
{
//    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    return qApp_.exec();
}


void Application::terminate()
{
    server_.inputBlocks().stopAll();
}
