#include "networkutility.hpp"

NetworkUtility::NetworkUtility()
{

}


QHostAddress NetworkUtility::getHostAddress()
{
    QHostAddress retValue;

    auto addresses = QNetworkInterface::allAddresses();

    foreach (auto addr, addresses)
    {
        if (addr.protocol() == QAbstractSocket::IPv4Protocol && !addr.isLoopback() )
        {
            retValue = addr;
            qDebug() << "server IPv4 address found : " << addr;
            break;
        }
    }

    return retValue;
}
