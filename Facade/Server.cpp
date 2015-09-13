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


// Maximum size of a message.
static const int LOG_RECORD_MAX = 1024;

// Port number to listen on for requests.
static const int LOGGING_PORT = 5555;

//Ip address. 127.0.0.1 for localhost. 192.168.1.71 for desktop
static char* IP_ADDRESS = "192.168.1.71";

// Entry point that writes logging records.
int write_record(char log_record[], int len)
{
	int a = 0;
	char array2[LOG_RECORD_MAX];
	while (a < len)
	{
		array2[a] = log_record[a];
		a++;
	}
	array2[a] = '\0';
	std::cout << "Received: " << array2 << std::endl;
	return 0;
}

// Entry point that processes logging records for one client connection.
void* logging_handler(void* arg)
{
	SOCKET h = reinterpret_cast<SOCKET>(arg);
	SockStreamFacade socket_stream(h);

	for (;;)
	{
		char log_record[LOG_RECORD_MAX];
		ssize_t n = socket_stream.recv(log_record, LOG_RECORD_MAX - 1, 0);
		// Bail out if an error occurs.
		if (n <= 0) return 0;
		MutexFacade mutex;
		mutex.aquire();
		// Execute following two statements in a critical section to avoid ace conditions and scrambled output, respectively.
		++request_count;
		// A return value of -1 signifies failure.
		if (write_record(log_record, n) == -1)
			break;
		mutex.release();
	}
	return 0;
}


// Main driver function for the server.
int main(int argc, char* argv[])
{
	//Initialize socket.
	WORD version_requested = MAKEWORD(2, 0);
	WSADATA wsa_data;
	int error = WSAStartup(version_requested, &wsa_data);
	if (error != 0) return -1;

	INETFacade address = INETFacade(LOGGING_PORT, IP_ADDRESS);
	SockAcceptorFacade sock_acceptor = SockAcceptorFacade(address);
	SockStreamFacade sock_stream;

	// Main server event loop.
	for (;;)
	{
		std::cout << "Waiting" << std::endl;
		//std::cout << "port: " << address.get_port() << std::endl;
		//std::cout << "address: " << address.get_ip_addr() << std::endl;

		
		DWORD t_id;
	    //Accept and wait for calls
		sock_acceptor.accept(sock_stream);
		std::cout << "Connected";
		CreateThread(0, 0, LPTHREAD_START_ROUTINE(&logging_handler), reinterpret_cast<void *>(sock_stream.get_handle()), 0, &t_id);
	}
	return 0;
}
