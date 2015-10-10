
#include "stdafx.h"
#include "reactor_lib.h"
#include "config.h"
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <thread>

using namespace std;

MutexFacade mutex;
Event_Log_Demux demux_;

void* threadRoutine()
{
	Queue* queueInstance = Queue::getInstance();

	for (;;)
	{
		
		mutex.aquire();
		if (queueInstance->CheckDequeuePossible())
		{
			auto member = queueInstance->Dequeue();
			mutex.release();
				auto stream_ = SOCK_Stream(member.handle);
				    
				    string demuxResponse = demux_.handle_log("2 5|Adrian");
					const char *response = demuxResponse.c_str();
					//write it back to the client
					stream_.send(response, strlen(response), 0);			
			
		}

		else
		{
			Sleep(1000);
			mutex.release();
		}
	}
	return 0;
}

int main()
{
	WORD version_requested = MAKEWORD(2, 0);
	WSADATA wsa_data;
	int error = WSAStartup(version_requested, &wsa_data);
	if (error != 0) return -1;

	Reactor_Select reactor;
	INET_Addr adr = INET_Addr(EVENT_PORT, IP_ADDRESS);
	Event_Acceptor ea(adr, &reactor);

	DWORD id1 = '1';
	DWORD id2 = '2';
	DWORD id3 = '3';

	CreateThread(0, 0, LPTHREAD_START_ROUTINE(&threadRoutine), 0, 0, &id1);
	CreateThread(0, 0, LPTHREAD_START_ROUTINE(&threadRoutine), 0, 0, &id2);
	CreateThread(0, 0, LPTHREAD_START_ROUTINE(&threadRoutine), 0, 0, &id3);

	while (true)
	{
		printf("Waiting for events...\n");
		reactor.handle_events();
	}

	return 0;
}