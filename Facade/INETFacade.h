#pragma once
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
class INETFacade
{
public:
	INETFacade(u_short port, char* addr);
	~INETFacade();
	u_short get_port() const ;
	u_long get_ip_addr() const ;
	sockaddr *addr();
	size_t size() const ;
private:
	sockaddr_in addr_;
};

