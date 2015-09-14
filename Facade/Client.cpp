#include "stdafx.h"
//#include <iostream>
//#include <windows.h>
//#pragma comment(lib, "ws2_32.lib")
//#include "INETFacade.h"
//#include "SockConnectorFacade.h"
//#include "SockStreamFacade.h"
//
//typedef int ssize_t;
//
//// Port number to listen on for requests.
//static const int LOGGING_PORT = 5555;
//
////Ip address. 127.0.0.1 for localhost. 192.168.1.71 for desktop
//static char* IP_ADDRESS = "192.168.1.71";
//
//
//// Main driver function for the client.
//int main(int argc, char *argv[]) {
//	WORD version_requested = MAKEWORD(2, 0);
//	WSADATA wsa_data;
//	int error = WSAStartup(version_requested, &wsa_data);
//	if (error != 0) return -1;
//	INETFacade address = INETFacade(LOGGING_PORT, IP_ADDRESS);
//	SockStreamFacade sockStream;
//	SockConnectorFacade sockConnector;
//	sockStream.set_handle(sockConnector.get_handle());
//
//	//Try to connect.
//	if (sockConnector.connect(address.addr(), address.size()) < 0)
//		std::cout << "ERROR opening socket"<<std::endl;
//	else std::cout << "socket opened" << std::endl;
//
//	//Try to send one message a second.
//	for (;;){
//		std::cout << "Sending" << std::endl;
//		if(sockStream.send("test",4,0)==-1)
//			std::cout << "error sending" << std::endl;
//		Sleep(1000);
//	}
//	return 0;
//}
