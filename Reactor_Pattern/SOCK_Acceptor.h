#pragma once
#include "stdafx.h"
#include "SOCK_Acceptor.h"
#pragma comment(lib, "ws2_32.lib")
#include "SOCK_Stream.h"
#include "INET_Addr.h"
#include <winsock.h>
#include "Reactor.h"
class SOCK_Acceptor
{
public:
	
	SOCK_Acceptor(INET_Addr &addr, Reactor *reactor);
	SOCK_Acceptor(INET_Addr &addr);
	// A second method to initialize a passivemode acceptor socket, analogously to the constructor.
	void open(const INET_Addr &sock_addr);
	// Accept a connection and initialize the <stream>.
	void accept(SOCK_Stream &s);
	SOCKET get_handle() const;
	~SOCK_Acceptor();
private:
	SOCKET handle_; // Socket handle factory.
};