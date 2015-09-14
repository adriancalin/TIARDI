#pragma once
#include "Event_Handler.h"
class Demux_Table {
public:
	void convert_to_fd_sets (fd_set &read_fds, fd_set &write_fds, fd_set &except_fds){
		// TO DO
		
	}
	struct Tuple {
		Event_Handler *event_handler_;
		Event_Type event_type_;
	};
	Tuple table_[FD_SETSIZE];
};