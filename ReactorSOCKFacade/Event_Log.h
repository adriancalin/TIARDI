#pragma once

#include "sock_lib.h"
#include "reactor_lib.h"
#include "Event_Log_Demux.h"

class Event_Log : Event_Handler
{
public:
	Event_Log(const SOCK_Stream &stream, Reactor *reactor);
	~Event_Log();
	void handle_event(Handle handle, Event_Type et) override;
	Handle get_handle() const override;

private:
	Reactor *reactor_;
	SOCK_Stream stream_;
	Event_Log_Demux demux_;
};