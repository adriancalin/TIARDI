#include "stdafx.h"
#include "reactor_lib.h"
#include "config.h"

using namespace std;

MutexFacade mutex;

//Method that contains the routine for each thread.
void* threadRoutine()
{
	Event_Log_Demux demux_;
	Queue* queueInstance = Queue::getInstance();
	for (;;)
	{
		//Use a mutex when checking/dequeing.
		mutex.aquire();
		if (queueInstance->CheckDequeuePossible())
		{
			auto member = queueInstance->Dequeue();
			mutex.release();
			//Initialize the socket and sent the event for demultiplexing
			SOCK_Stream* stream_ = new SOCK_Stream(member.handle);

			string demuxResponse = demux_.handle_log(member.buffer);
			const char* response = demuxResponse.c_str();
			//Send the response to the client
			stream_->send(response, strlen(response), 0);
		}
		//If queue empty, wait for a second and check again.
		else
		{
			mutex.release();
			Sleep(1000);
		}
	}
}

int main()
{
	WORD version_requested = MAKEWORD(2, 0);
	WSADATA wsa_data;
	int error = WSAStartup(version_requested, &wsa_data);
	if (error != 0) return -1;
	//Initialize Reactor and Acceptor
	Reactor_Select reactor;
	INET_Addr adr = INET_Addr(EVENT_PORT, IP_ADDRESS);
	Event_Acceptor ea(adr, &reactor);
	//Initialize the 3 threads that read/write to file
	DWORD id1 = '1';
	DWORD id2 = '2';
	DWORD id3 = '3';
	CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(&threadRoutine), nullptr, 0, &id1);
	CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(&threadRoutine), nullptr, 0, &id2);
	CreateThread(nullptr, 0, LPTHREAD_START_ROUTINE(&threadRoutine), nullptr, 0, &id3);
	//Event handler loop
	while (true)
	{
		printf("Waiting for events...\n");
		reactor.handle_events();
	}
}
