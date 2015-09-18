#pragma once

#include "stdafx.h"
#include "reactor_lib.h"


class Demux_Table {
public:
	void convert_to_fd_sets(fd_set &read_fds, fd_set &write_fds, fd_set &except_fds)
	{
		
	}
	
	struct Tuple {
		Event_Handler *event_handler_;
		Event_Type event_type_;
	};

	Tuple table_[FD_SETSIZE];
};