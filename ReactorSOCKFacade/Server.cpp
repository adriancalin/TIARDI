#include "stdafx.h"
//#include "reactor_lib.h"
//#include "config.h"
//
//int main()
//{
//	WORD version_requested = MAKEWORD(2, 0);
//	WSADATA wsa_data;
//	int error = WSAStartup(version_requested, &wsa_data);
//	if (error != 0) return -1;
//
//	Reactor_Select reactor;
//	INET_Addr adr = INET_Addr(EVENT_PORT, IP_ADDRESS);
//	Event_Acceptor ea(adr, &reactor);
//
//	while (true)
//	{
//		printf("Waiting for events...\n");
//		reactor.handle_events();
//	}
//
//	return 0;
//}