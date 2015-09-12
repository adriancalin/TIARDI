#pragma once
#include <winsock.h>
#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")
#include "SockStreamFacade.h"
#include "INETFacade.h"

class SockAcceptorFacade
{
public:
	SockAcceptorFacade(INETFacade &addr);
	// A second method to initialize a passivemode acceptor socket, analogously to the constructor.
	void open(const INETFacade &sock_addr);
	// Accept a connection and initialize the <stream>.
	void acceptOverwritten(SockStreamFacade &s);
	~SockAcceptorFacade();	
private:
	SOCKET handle_; // Socket handle factory.
};


