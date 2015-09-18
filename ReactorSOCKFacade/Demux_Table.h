#pragma once

#include "stdafx.h"
#include "reactor_lib.h"
#include <vector>


typedef struct Tuple {
	Event_Handler *event_handler_;
	Event_Type event_type_;
} Event_Tuple;

class Demux_Table {
public:
	void convert_to_fd_sets(fd_set &read_fds, fd_set &write_fds, fd_set &except_fds);
	std::vector <Event_Tuple> table_;
};