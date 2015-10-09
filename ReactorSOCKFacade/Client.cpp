#include "stdafx.h"

/*
#include "sock_lib.h"
#include "reactor_lib.h"

#include "config.h"

Event_Service_Handler sh;

void ConcreteServiceHandle(Handle peer_stream)
{
	sh.open(peer_stream);
}


int main(int argc, char *argv[]) {
	WORD version_requested = MAKEWORD(2, 0);
	WSADATA WSA_Data;
	int error = WSAStartup(version_requested, &WSA_Data);
	if (error != 0) return -1;
	
	INET_Addr address = INET_Addr(EVENT_PORT, IP_ADDRESS);
	Reactor_Select reactor;
	sh = Event_Service_Handler(&reactor);
	Event_Connector connector(&reactor);
	
	connector.connect(ConcreteServiceHandle, address);

	while (true)
	{
		reactor.handle_events();
	}
}
*/
