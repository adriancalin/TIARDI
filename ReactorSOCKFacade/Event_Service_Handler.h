#pragma once

#include "reactor_lib.h"
#include "sock_lib.h"

class Event_Service_Handler : public Event_Handler
{
public:
	Event_Service_Handler();
	Event_Service_Handler(Reactor* reactor);
	~Event_Service_Handler();
	void handle_event(Handle handle, Event_Type et) override;
	Handle get_handle() const override;
	void open(Handle stream);

private:
	Reactor* reactor_;
	SOCK_Stream handle_;
	int STATE;
};
