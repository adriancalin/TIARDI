#pragma once

#include <map>
#include "stdafx.h"
#include "reactor_lib.h"

typedef struct Tuple {
	Event_Handler *event_handler_;
	Event_Type event_type_;
} Event_Tuple;

class Demux_Table {
public:
	void convert_to_fd_sets(fd_set &read_fds, fd_set &write_fds, fd_set &except_fds);
	std::map<Handle, Event_Tuple> table_;
};