
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

string get_patient_from_file2(string cpr)
{
	string line;
	ifstream myfile("patients.txt");
	if (myfile.is_open())
	{
		//read all the lines
		while (getline(myfile, line))
		{
			stringstream ssLine(line);
			string segment;
			vector<string> seglist; // used for storing the patient cpr & info
									//get the words separated by '-' -> segment)
			while (getline(ssLine, segment, '-'))
			{
				seglist.push_back(segment);
			}
			//is the first value in the vector equal to the cpr we are looking for?
			if (cpr.compare(seglist[0]) == 0)
			{
				string &patient_name = seglist[1];
				myfile.close();
				return patient_name;
			}
		}

		myfile.close();
	}
	//in case no patient was found with the specified cpr
	return "Patient not found!";
}

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
				    string patientInfo = get_patient_from_file2(member.buffer);

					const char *response = patientInfo.c_str();
					//write it back to the client
					stream_.send(response, strlen(response), 0);			
			
		}

		else
		{
			Sleep(1000);
			mutex.release();
		}
		/*auto myid = std::this_thread::get_id();
		std::stringstream ss;
		ss << myid;
		std::string mystring = ss.str()+"\n";
		printf(mystring.c_str());*/
		
		/*queueInstance->CheckDequeuePossible();
		int x = queueInstance->GetQueueSize();
		std::stringstream ss;
		ss << x;
		std::string mystring = ss.str() + "\n";
		printf(mystring.c_str());
		mutex.release();*/
		/*if (queueInstance->CheckDequeuePossible())
		{

		}
		else
		{
			Sleep(1000);
		}*/
		

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