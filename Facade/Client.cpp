

#include "stdafx.h"
#include <iostream>
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")
#include "MutexFacade.h"
#include "SockStreamFacade.h"
#include "SockAcceptorFacade.h"

typedef int ssize_t;
// Keep track of number of logging requests.
static int request_count;


// Maximum size of a logging record.
static const int LOG_RECORD_MAX = 1024;
// Port number to listen on for requests.
static const int LOGGING_PORT = 10000;
// Entry point that writes logging records.
int write_record(char
	log_record[], int len) {
	/* ... */
	return 0;
}
// Entry point that processes logging records for one client connection.

void *logging_handler(void *arg)
{

	SOCKET h = reinterpret_cast <SOCKET>(arg);

	SockStreamFacade socket_stream(h);

	for (;;) {
		ULONG len;
		char log_record[LOG_RECORD_MAX];
		// The first <recv>	reads the length (stored as a 32-bit integer) of adjacent logging record.This code does not handle "short-<recv>s".

		ssize_t n = socket_stream.recv(reinterpret_cast <char *>(&len), sizeof len, 0);
		// Bail out if we're shutdown or errors occur unexpectedly.
		if (n <= 0)
			break;
		len = ntohl(len);
		if (len >LOG_RECORD_MAX) break;
		// The second <recv> then reads <len> bytes to obtain the actual record. This code handles "short-<recv>s".
		n = socket_stream.recv(log_record, len, 0);
		// Bail out if an error occurs.
		if (n <= 0) return 0;
		MutexFacade mutex;
		mutex.aquire();
		// Execute following two statements in a critical section to avoid ace conditions and scrambled output, respectively.
		++request_count;
		// A return value of -1 signifies failure.
		if (write_record(log_record, len) == -1)
			break;
		mutex.release();
	}
	return 0;
}


// Main driver function for the server.
int main(int argc, char *argv[]) {
	WORD version_requested = MAKEWORD(2, 0);
	WSADATA wsa_data;
	int error = WSAStartup(version_requested, &wsa_data);
	if (error != 0) return -1;
	struct sockaddr_in sock_addr;
	SOCKET sender;
	sender = socket(PF_INET, SOCK_STREAM, 0);
	INETFacade address = INETFacade(5555, 0);
	//SockAcceptorFacade sock_acceptor = SockAcceptorFacade(address);
	std::cout << "port: " << address.get_port() << std::endl;
	std::cout << "address: " << address.get_ip_addr() << std::endl;
	if (connect(sender, address.addr(), address.size()) < 0)
		int i = 1;
	int i = 2;
	// Create a local endpoint of communication.
	//acceptor = socket(AF_INET,SOCK_STREAM, 0);


	// Set up the address to become a server.
	//memset(&sock_addr, 0, sizeof sock_addr);
	//sock_addr.sin_family = PF_INET;
	//sock_addr.sin_port = htons(LOGGING_PORT);
	//sock_addr.sin_addr.s_addr = htonl(INADDR_ANY);	
	// Associate address with endpoint.
	//bind(acceptor, reinterpret_cast<struct sockaddr *>(&sock_addr), sizeof sock_addr);
	// Make endpoint listen for connections.
	//listen(acceptor, 5);
	// Main server event loop.
	/*for (;;) {
		std::cout << "client";
		// Handle UNIX/Win32 portability.
		//SockStreamFacade h;
		DWORD t_id;
		// Block waiting for clients to connect.
		//h = sock_acceptor.accept();
		//h = accept (acceptor, 0, 0);
		// Spawn a new thread that runs	the <server> entry point.
		sock_acceptor.acceptOverwritten(sock_stream);
		std::cout << "Connected";
		SOCKET h = sock_stream.get_handle();
		CreateThread(0, 0, LPTHREAD_START_ROUTINE(&logging_handler), reinterpret_cast <void *>(h), 0, &t_id);
	}*/
	return 0;
}
