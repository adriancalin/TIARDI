#include "stdafx.h"

#include "reactor_lib.h"

using ::Event_Service_Handler;
using std::cout;

Event_Service_Handler::Event_Service_Handler() {}

Event_Service_Handler::Event_Service_Handler(Reactor *reactor) : reactor_(reactor) {}

Event_Service_Handler::~Event_Service_Handler() {}

void Event_Service_Handler::handle_event(Handle handle, Event_Type et)
{
	// TODO 
}

Handle Event_Service_Handler::get_handle() const
{
	return handle_.get_handle();
}

void Event_Service_Handler::open(Handle stream)
{
	cout << "Connector initialized stream";
}