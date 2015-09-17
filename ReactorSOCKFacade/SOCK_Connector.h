#pragma once

#include "stdafx.h"
#include "sock_stream.h"

class SOCK_Connector
{
public:
	SOCK_Connector();
	int connect(sockaddr* addr, size_t len);
	SOCKET get_handle() const;
	~SOCK_Connector();

private:
	SOCKET handle_;
};

