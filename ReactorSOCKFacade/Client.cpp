#include "stdafx.h"
//#include "sock_lib.h"
//#include "config.h"
//
//
//// Main driver function for the client.
//int main(int argc, char *argv[]) {
//	WORD version_requested = MAKEWORD(2, 0);
//	WSADATA wsa_data;
//	int error = WSAStartup(version_requested, &wsa_data);
//	if (error != 0) return -1;
//	INET_Addr address = INET_Addr(EVENT_PORT, IP_ADDRESS);
//	SOCK_Stream sockStream;
//	SOCK_Connector sockConnector;
//	sockStream.set_handle(sockConnector.get_handle());
//
//	//Try to connect.
//	if (sockConnector.connect(address.addr(), address.size()) < 0)
//		std::cout << "Client: ERROR opening socket" << std::endl;
//	else std::cout << "Client: socket opened" << std::endl;
//
//	char *alarm = "1 42|Sample alarm text";
//	char *patient_info = "2 SAMPLE_TYPE|Sample patient value";
//	char *simple_log = "3 Sample simple log message";
//
//	// Try to send a different alarm event every 5 seconds.
//	for (;;) {
//		std::cout << "Sending new batch of alarms..." << std::endl;
//		if (sockStream.send(alarm, strlen(alarm), 0) == -1)
//			std::cout << "Client: error sending alarm" << std::endl;
//		Sleep(5000);
//		if (sockStream.send(patient_info, strlen(patient_info), 0) == -1)
//			std::cout << "Client: error sending patient info" << std::endl;
//		Sleep(5000);
//		if (sockStream.send(simple_log, strlen(simple_log), 0) == -1)
//			std::cout << "Client: error sending log" << std::endl;
//		Sleep(5000);
//	}
//	
//	return 0;
//}
