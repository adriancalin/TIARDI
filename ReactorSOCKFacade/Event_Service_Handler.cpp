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
			cout << "Please enter an event: ";
			string input;
			getline(cin, input);
			handle_.send(input.c_str(), strlen(input.c_str()), 0);

			// Preparing ourselves to read data

			reactor_->remove_handler(this, WRITE_EVENT);
			reactor_->register_handler(this, READ_EVENT);
			STATE = WRITE_OUTPUT;
		} break;
		case WRITE_OUTPUT: 
		{
			// TO DO 
		}
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