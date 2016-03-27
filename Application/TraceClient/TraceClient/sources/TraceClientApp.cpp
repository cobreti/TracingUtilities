#include "sources/TraceClientApp.hpp"
#include "tcpinputblock.hpp"
#include "MainWindow.hpp"
#include "server.hpp"


TraceClientApp::TraceClientApp(int argc, char *argv[]) : QObject(),
    qApp_{argc, argv},
    pServer_{nullptr},
    pMainWindow_{nullptr}
{
}


TraceClientApp::~TraceClientApp()
{
//    delete pMainWindow_;
    delete pServer_;
}


void TraceClientApp::run()
{
    startTimer_.setSingleShot(true);
    startTimer_.start(200);

    connect(    &startTimer_, SIGNAL(timeout()),
                this, SLOT(onStart()) );

    pMainWindow_ = new MainWindow();
    pMainWindow_->show();

    qApp_.exec();

    disconnect( &startTimer_, SIGNAL(timeout()),
                this, SLOT(onStart()) );

    delete pMainWindow_;
    pMainWindow_ = nullptr;
}


void TraceClientApp::onStart()
{
    TraceServer::InputBlock *pBlock = nullptr;

    try
    {
        pServer_ = new TraceServer::Server();
        pServer_->start();

        pBlock = new TraceServer::TcpInputBlock("default", 5000);

        pServer_->inputBlocks().add(pBlock);

        pServer_->inputBlocks().startAll();
    }
    catch (std::exception& err)
    {
        delete pBlock;

        qCritical() << "error when creating input block : " << err.what();
    }
}
