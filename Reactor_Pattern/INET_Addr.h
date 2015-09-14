#pragma once
#pragma comment(lib, "ws2_32.lib")
#include <winsock.h>
class INET_Addr
{
public:
	INET_Addr(u_short port, u_long addr);
	~INET_Addr();
	u_short get_port() const ;
	u_long get_ip_addr() const ;
	sockaddr *addr();
	size_t size() const ;
private:
	sockaddr_in addr_;
};