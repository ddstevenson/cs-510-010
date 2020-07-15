#include "servInfo.h"




ServerInfo::ServerInfo() { } 
ServerInfo::ServerInfo(std::string p_ip, unsigned int p_port) {
	setServerInfo(p_ip, p_port); 
}


void ServerInfo::setServerInfo(std::string p_ip, unsigned int p_port) {
	ip = p_ip; 
	port = p_port; 
}
