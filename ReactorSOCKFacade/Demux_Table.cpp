#include "stdafx.h"
#include "reactor_lib.h"

using ::Demux_Table;

void Demux_Table::convert_to_fd_sets(fd_set& read_fds, fd_set& write_fds, fd_set& except_fds)
{

	// TODO consider using FD_ZERO to initialize sets to 0.
	
	FD_ZERO(&read_fds);
	FD_ZERO(&write_fds);

	for (std::vector<Event_Tuple>::iterator it = table_.begin(); it != table_.end(); ++it)
	{
		// TODO consider using FD_SET rather than direct access of members	
		if (it->event_type_ == READ_EVENT || it->event_type_ == ACCEPT_EVENT)
		{
			FD_SET(it->event_handler_->get_handle(), &read_fds);
		}
		else if (it->event_type_ == WRITE_EVENT) {
//			write_fds.fd_array[read_fds.fd_count] = it->event_handler_->get_handle();
//			++write_fds.fd_count;
		} else
		{
			// TODO other cases?
		}

		
	}
}
