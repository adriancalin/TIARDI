#include "stdafx.h"
#include "sock_lib.h"


SOCK_Acceptor::SOCK_Acceptor(INET_Addr& addr)
{
	// Create a local endpoint ofcommunication.
	handle_ = socket(AF_INET, SOCK_STREAM, 0);
	// Associate address with endpoint.
	bind(handle_, addr.addr(), addr.size());
	// Make endpoint listen for connections.
	listen(handle_, 5);
}

SOCK_Acceptor::~SOCK_Acceptor()
{
	// No resource to release
}

void SOCK_Acceptor::accept(SOCK_Stream& s)
{
	s.set_handle(_WINSOCKAPI_::accept(handle_, 0, 0));
}