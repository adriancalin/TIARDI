#pragma once

#include "sock_lib.h"

typedef void (*ServiceHandle)(Handle);

class Event_Connector : Event_Handler
{
public:
	Event_Connector(Reactor* reactor);
	~Event_Connector();
	void handle_event(Handle handle, Event_Type et) override;
	Handle get_handle() const override;
	void connect(ServiceHandle sh, INET_Addr addr);

private:
	SOCK_Connector connector_;
	Reactor* reactor_;
	ServiceHandle sh_;
};
