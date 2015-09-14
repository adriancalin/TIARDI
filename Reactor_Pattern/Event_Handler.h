#pragma once
#include "Event_Type.h"
class Event_Handler{
public:
	virtual void handle_event (Handle handle, Event_Type et) = 0;
	virtual Handle get_handle() const = 0;
protected:
	virtual ~Event_Handler ();
};