#include "stdafx.h"
#include "reactor_lib.h"
#include <map>

using ::Reactor_Select;
using std::map;

Reactor_Select::~Reactor_Select()
{
	// No resource to clear
}

void Reactor_Select::register_handler(Event_Handler* eh, Event_Type et)
{
	Handle handle = eh->get_handle();
	register_handler(handle, eh, et);
}

void Reactor_Select::register_handler(Handle h, Event_Handler* eh, Event_Type et)
{
	demux_table.table_[h] = Event_Tuple{eh, et};
}

void Reactor_Select::remove_handler(Event_Handler* eh, Event_Type et)
{
	Handle handle = eh->get_handle();
	remove_handler(handle, et);
}

void Reactor_Select::remove_handler(Handle h, Event_Type et)
{
	demux_table.table_[h].event_handler_ = nullptr;
	demux_table.table_[h].event_type_ = NULL;
}

void Reactor_Select::handle_events(Time_Value* timeout)
{
	fd_set read_fds, write_fds, except_fds;
	demux_table.convert_to_fd_sets(read_fds, write_fds, except_fds);
	int result = select(0, &read_fds, &write_fds, &except_fds, timeout);
	if (result <= 0) printf("select() returned with error %d\n", WSAGetLastError());
	map<Handle, Event_Tuple>::iterator it;
	if (result > 0)
	{
		for (it = demux_table.table_.begin(); it != demux_table.table_.end(); ++it)
		{
			if (FD_ISSET(it->first, &read_fds))
			{
				it->second.event_handler_->handle_event(it->first, it->second.event_type_);
			}
			else if (FD_ISSET(it->first, &write_fds))
			{
				it->second.event_handler_->handle_event(it->first, it->second.event_type_);
			}
		}
	}
}
