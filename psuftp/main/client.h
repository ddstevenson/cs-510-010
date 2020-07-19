#include "servInfo.h"
#include "user.h"
#include <iostream>
#include <limits>
#include <sstream>
#include <string>

class Client
{
private:
    ServerInfo singleServ; // Single user for now
    User       singleUser;

public:
    Client();
    int getServer();
    int getUser();

protected:
    int handleInputError(std::string errorString);
};
