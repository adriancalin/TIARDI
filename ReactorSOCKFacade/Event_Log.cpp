#include "stdafx.h"
#include "sock_lib.h"
#include "reactor_lib.h"
#include "config.h"
#include <map>
#include <string>
#include <vector>
#include <sstream>
#include <fstream>


using namespace std;
using ::Event_Log;

Event_Log::Event_Log(const SOCK_Stream& stream, Reactor* reactor) : stream_(stream), reactor_(reactor)
{
	
	reactor->register_handler(this, READ_EVENT);
}

Event_Log::~Event_Log() 
{
	std::cout << "Removing handler..." << std::endl;
	reactor_->remove_handler(this, READ_EVENT);
}

string get_patient_from_file(string cpr)
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

void Event_Log::handle_event(Handle handle, Event_Type et)
{
	
	
	if (et == READ_EVENT)
	{
		char buffer[EVENT_MAX_SIZE];
		int len = stream_.recv(buffer, EVENT_MAX_SIZE, 0);
		if (len <= 0) delete this;
		else
		{
			buffer[len] = '\0';
			auto queue = Queue::getInstance();
			queue->Enqueue(QueueMember{handle,string(buffer, 0, len) });
			// get the patient information
			//string patientInfo = get_patient_from_file(string(buffer, 0, len));

			//const char *response = patientInfo.c_str();
			//write it back to the client
			//stream_.send(response, strlen(response), 0);
		}	
	}
}

Handle Event_Log::get_handle() const
{
	return stream_.get_handle();
}