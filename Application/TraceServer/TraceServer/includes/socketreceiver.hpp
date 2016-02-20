#ifndef SOCKETRECEIVER_HPP
#define SOCKETRECEIVER_HPP

#include <QtCore>
#include <QtNetwork>

namespace TraceServer
{
    class SocketReceiver : public QObject, public QRunnable
    {
        Q_OBJECT

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

    protected:

        QTcpSocket      *pSocket_;
        bool            connected_;
        QEventLoop      *pEventLoop_;
        char            *pBuffer_;
        int             bufferSize_;
    };
}

#endif // SOCKETRECEIVER_HPP
