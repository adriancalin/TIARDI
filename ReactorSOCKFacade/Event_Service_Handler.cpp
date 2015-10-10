#include "stdafx.h"

#include "reactor_lib.h"
#include <string>

using ::Event_Service_Handler;
using std::cout;		using std::cin;
using std::getline;		using std::string;
using std::endl;	

#define READ_INPUT 1
#define WRITE_OUTPUT 2

Event_Service_Handler::Event_Service_Handler() {}

Event_Service_Handler::Event_Service_Handler(Reactor *reactor) : reactor_(reactor) {}

Event_Service_Handler::~Event_Service_Handler() {}

void Event_Service_Handler::handle_event(Handle handle, Event_Type et)
{

	switch(STATE)
	{
		case READ_INPUT: 
		{
			string input; 
			// 1 - request patient info event; 2 - send patient info
			string et1("1");
			string et2("2");

			//read the event type from keyboard
			string eventType;
			do
			{
				cout << "Choose either request or send event\n";
				cout << "Enter 1 for request or 2 for send: ";
				getline(cin, eventType);

			} while ((eventType != et1) && (eventType != et2));
			cout << "\n";

			if (eventType == "1")
			{
				//read the cpr value from keyboard
				string cpr;
				do
				{
					cout << "Please enter desired patient's cpr: ";
					getline(cin, cpr);
				} while (cpr.length() <= 0);
				cout << "\n";
				//format the input according to the request patient info event type
				input = "1 " + cpr;
			}
			else
			{
				string cpr, name;
				//read the cpr value from keyboard
				do
				{
					cout << "Please enter the new patient's cpr: ";
					getline(cin, cpr);
				} while (cpr.length() <= 0);

				//read the name value from keyboard
				do
				{
					cout << "Please enter the new patient's name: ";
					getline(cin, name);
				} while (name.length() <= 0);
				cout << "\n";
				//format the input according to the send patient info event type
				input = "2 " + cpr + "|" + name;
			}
			cout << "\n";


			handle_.send(input.c_str(), strlen(input.c_str()), 0);

			// Preparing ourselves to read data

			reactor_->remove_handler(this, WRITE_EVENT);
			reactor_->register_handler(this, READ_EVENT);
			STATE = WRITE_OUTPUT;
		} break;
		case WRITE_OUTPUT: 
		{
			char buffer[1000];
			int len = handle_.recv(buffer, 1000, 0);
			buffer[len] = '\0';
			cout << "Server response: " << string(buffer, 0, len) << endl;

			// Prepare ourselves to write data

			reactor_->remove_handler(this, READ_EVENT);
			reactor_->register_handler(this, WRITE_EVENT);
			STATE = READ_INPUT;

		} break;
	}
	
}

Handle Event_Service_Handler::get_handle() const
{
	return handle_.get_handle();
}

void Event_Service_Handler::open(Handle stream)
{
	cout << "Connector initialized stream" << endl;
	handle_.set_handle(stream);
	STATE = READ_INPUT;
	reactor_->register_handler(this, WRITE_EVENT);
}