#include "stdafx.h"
#include "sock_lib.h"
#include "reactor_lib.h"

using ::Event_Log;

Event_Log::Event_Log(const SOCK_Stream& stream, Reactor* reactor) : stream_(stream), reactor_(reactor)
{
	
	reactor->register_handler(this, READ_EVENT);
}

Event_Log::~Event_Log() 
{
	// TODO 
	//	reactor_->remove_handler(this, READ_EVENT);
}

void Event_Log::handle_event(Handle handle, Event_Type et)
{
	if (et == READ_EVENT)
	{
		char buffer[1024];
		int len = stream_.recv(buffer, 1024, 0);
		if (len <= 0) delete this;
		else
		{
			buffer[len] = '\0';
			demux_.handle_log(buffer);
		}
		
	}
}

Handle Event_Log::get_handle() const
{
	return stream_.get_handle();
}