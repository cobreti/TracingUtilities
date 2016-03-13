#ifndef SOCKETRECEIVER_HPP
#define SOCKETRECEIVER_HPP

#include <QtCore>
#include <QtNetwork>
#include <vector>

#include "databuffer.hpp"
#include "dataparser.hpp"
#include "primarystorage.hpp"


namespace TraceServer
{
    class SocketReceiver : public QObject, public QRunnable
    {
        Q_OBJECT

        enum
        {
            kBufferSize = 8 * 1024
        };

    public:
        SocketReceiver(QTcpSocket* pSocket);
        virtual ~SocketReceiver();

        SocketReceiver(const SocketReceiver&) = delete;
        const SocketReceiver& operator = (const SocketReceiver&) = delete;

        virtual void run() override;

    public slots:

        void onSocketConnected();
        void onSocketDisconnected();
        void onReadyRead();
        void onSocketError(QAbstractSocket::SocketError socketError);
        void onMonitorTimeout();

    protected:

        void processBuffer();

    protected:

        QTcpSocket                  *pSocket_;
        bool                        connected_;
        QEventLoop                  *pEventLoop_;
        DataBuffer                  dataBuffer_;
        DataParser                  dataParser_;
        PrimaryStorage              primaryStorage_;
        QTimer                      monitorTimer_;
        int                         bytesRead_;
    };
}

#endif // SOCKETRECEIVER_HPP
