#pragma once
#include "reactor_lib.h"

class Event_Handler {
public:
	virtual ~Event_Handler();
	virtual void handle_event(Handle handle, Event_Type et) = 0;
	virtual Handle get_handle() const = 0;
};