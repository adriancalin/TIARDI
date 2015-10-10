#include "stdafx.h"
#include "sock_lib.h"


INET_Addr::INET_Addr(u_short port, char* addr)
{
	// Set up the address to become a server.
	memset(&addr_, 0, sizeof addr_);
	addr_.sin_family = AF_INET ;
	addr_.sin_port = htons(port);
	addr_.sin_addr.s_addr = inet_addr(addr);
}


INET_Addr::~INET_Addr()
{
	// No resources to release
}

u_short INET_Addr::get_port() const
{
	return addr_.sin_port;
}

u_long INET_Addr::get_ip_addr() const
{
	return addr_.sin_addr.s_addr ;
}

sockaddr* INET_Addr::addr()
{
	return reinterpret_cast<sockaddr *>(&addr_);
}


size_t INET_Addr::size() const
{
	return sizeof(addr_);
}
