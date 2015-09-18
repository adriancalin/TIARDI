#pragma once

#include "reactor_lib.h"

class Reactor_Select : Reactor
{
public:
	~Reactor_Select();
	void register_handler(Event_Handler *eh, Event_Type et) override;
	void register_handler(Handle h, Event_Handler *eh, Event_Type et) override;
	void remove_handler(Event_Handler *eh, Event_Type et) override;
	void remove_handler(Handle h, Event_Type et) override;
	void handle_events(Time_Value *timeout = 0) override;
};