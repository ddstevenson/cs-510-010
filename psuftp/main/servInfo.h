#include <iostream>
#include <sstream>
#include <string>

class ServerInfo
{
private:
    std::string  ip;
    unsigned int port;

public:
    ServerInfo();
    ServerInfo(std::string p_ip, unsigned int p_port);
    void setServerInfo(std::string p_ip, unsigned int p_port);
};
