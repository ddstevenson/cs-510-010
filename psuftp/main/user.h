#include <iostream>
#include <string>
#include <sstream>
using namespace std;


class User {
	private: 
	string username; 
	string ip; 
	unsigned int port; 
	string pass; // Do not Check In an Actual Password I will make it set dynamically!

	public: 
	User(); 
	User(string p_username,  string p_pass); 
	void populateUser(string p_username,  string p_pass); 

	string getUsername() { return username; } 
//	string getIp() { return ip; } 
//	unsigned int getPort() { return port; } 
	string getPass() { return pass; } 
	

};
