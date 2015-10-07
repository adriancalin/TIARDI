#include "stdafx.h"

#include "reactor_lib.h"

using ::Event_Connector;

Event_Connector::Event_Connector(Reactor* reactor_)
{
	
}

Event_Connector::~Event_Connector()
{

}

void Event_Connector::handle_event(Handle handle, Event_Type et)
{

}

Handle Event_Connector::get_handle() const
{

}

void Event_Connector::connect(ConnectHandler ch, INET_Addr addr)
{

}