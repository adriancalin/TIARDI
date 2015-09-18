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
	// No resources to release
}

void Event_Log::handle_event(Handle handle, Event_Type et)
{
	// TOOD
}

Handle Event_Log::get_handle() const
{
	return stream_.get_handle();
}