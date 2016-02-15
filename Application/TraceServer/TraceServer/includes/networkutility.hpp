#ifndef NETWORKUTILITY_HPP
#define NETWORKUTILITY_HPP

#include <QtNetwork>

class NetworkUtility
{
public:
    NetworkUtility();

    NetworkUtility(const NetworkUtility&) = delete;
    const NetworkUtility& operator = (const NetworkUtility&) = delete;

    QHostAddress getHostAddress();
};

#endif // NETWORKUTILITY_HPP
