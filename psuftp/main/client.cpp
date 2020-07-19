#include "client.h"

Client::Client() {}
int Client::getServer() {
    string       ip;
    unsigned int port;

    std::cout << "Ip Address (String format): ";
    std::cin >> ip;
    if (std::cin.fail()) {
        return handleInputError("Not a String");
    }
    // TODO Validate Input is an IP address

    std::cout << " Port (Numberic format): ";
    std::cin >> port;
    if (std::cin.fail()) {
        return handleInputError("Not a Number");
    }
    singleServ.setServerInfo(ip, port);

    return 0;
}

int Client::getUser() {
    string username;
    string userPass;

    std::cout << "Username (String format): ";
    std::cin >> username;
    if (std::cin.fail()) {
        return handleInputError("Not a String");
    }

    std::cout << " Password (String format): ";
    std::cin >> userPass;
    if (std::cin.fail()) {
        return handleInputError("Not a String");
    }
    singleUser.populateUser(username, userPass);

    return 0;
}

int Client::handleInputError(std::string errorString) {
    std::cout << "Not a Number\n";
    std::cin.clear(); // clear iostream error bits
    std::cin.ignore(std::numeric_limits<std::streamsize>::max());
    return -1;
}
