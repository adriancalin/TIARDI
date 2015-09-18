#pragma once
#include "reactor_lib.h"

class Reactor {
public:
	virtual void register_handler(Event_Handler *eh, Event_Type et) = 0;
	virtual void register_handler(Handle h, Event_Handler *eh, Event_Type et) = 0;
	virtual void remove_handler(Event_Handler *eh, Event_Type et) = 0;
	virtual void remove_handler(Handle h, Event_Type et) = 0;
	virtual void handle_events(Time_Value *timeout = 0) = 0;

protected:
	Demux_Table demux_table;
};