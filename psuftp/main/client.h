#include <iostream>
#include <string>
#include <sstream>
#include <limits>
#include "servInfo.h"
#include "user.h"

class Client { 
	private: 
	ServerInfo singleServ; // Single user for now
	User singleUser;
	public: 
		Client(); 
		int getServer();
		int getUser();
	protected: 
		int handleInputError(std::string errorString);

}; 
