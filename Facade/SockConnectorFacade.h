#pragma once
#include <winsock.h>
#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "SockStreamFacade.h"
#include "INETFacade.h"

class SockConnectorFacade
{
public:
	SockConnectorFacade();
	int connect(sockaddr* addr, size_t len);
	SOCKET get_handle() const;
	~SockConnectorFacade();
private:
	SOCKET handle_; // Socket handle factory.
};

