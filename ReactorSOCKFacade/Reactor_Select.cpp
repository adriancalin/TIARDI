#include "stdafx.h"
#include "reactor_lib.h"

using ::Reactor_Select;

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
	Event_Tuple event_tuple = { eh, et };
	demux_table.table_.push_back(event_tuple);

}

void Reactor_Select::remove_handler(Event_Handler* eh, Event_Type et)
{
	Handle handle = eh->get_handle();
	remove_handler(handle, et);
}

void Reactor_Select::remove_handler(Handle h, Event_Type et)
{
	// demux_table.table_[h].event_type_ = 0;
	for (std::vector<Event_Tuple>::iterator it = demux_table.table_.begin(); it != demux_table.table_.end(); ++it)
	{
		if (it->event_handler_->get_handle() == h)
		{
			demux_table.table_.erase(it);
		}
	}
}

void Reactor_Select::handle_events(Time_Value *timeout)
{
	fd_set read_fds, write_fds, except_fds;
	demux_table.convert_to_fd_sets(read_fds, write_fds, except_fds);
	Handle MAX_HANDLE = FD_SETSIZE;
	int result = select(0, &read_fds, &write_fds, NULL, NULL);
	printf("handle_events->result=%d", result);
	if (result <= 0) throw; // handle error or timeout cases here
	for (Handle h = 0; h <= MAX_HANDLE; h++) {

		for (std::vector<Event_Tuple>::iterator it = demux_table.table_.begin(); it != demux_table.table_.end(); ++it)
		{
			if (FD_ISSET(it->event_handler_->get_handle(), &read_fds))
			{
				it->event_handler_->handle_event(read_fds.fd_array[h], READ_EVENT);
			}
		}
		
		if (FD_ISSET(h, &write_fds))
		{
			// TODO
		}
	}
}