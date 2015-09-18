#pragma once

#include "sock_lib.h"
#include "reactor_lib.h"

class Event_Acceptor : public Event_Handler
{
public:
	Event_Acceptor(INET_Addr &addr, Reactor *reactor);
	~Event_Acceptor();
	void handle_event(Handle handle, Event_Type et) override;
	Handle get_handle() const override;

private:
	Reactor *reactor_;
	SOCK_Acceptor acceptor_;
};