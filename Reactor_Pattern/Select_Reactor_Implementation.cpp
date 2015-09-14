#pragma once
#include "stdafx.h"
#include "Reactor_Implementation.h"
#include "Demux_Table.h"
#include "Reactor.h"

class Select_Reactor_Implementation:public Reactor_Implementation {
public:
	void Select_Reactor_Implementation::register_handler(Event_Handler *event_handler, Event_Type event_type) {
	  // Double-dispatch to obtain the <HANDLE>.
	 Handle handle = event_handler->get_handle ();
	  }
	void Select_Reactor_Implementation::handle_events(Time_Value *timeout = 0){
		fd_set read_fds, write_fds, except_fds;
		demux_table.convert_to_fd_sets(read_fds,write_fds,except_fds);
		Handle max_handle = 32;
		int result = select( max_handle+1, &read_fds, &write_fds, &except_fds, timeout);
		if (result <=0) throw; // handle error or timeout cases here
		for (Handle h=0; h <= max_handle; h++) {
		 if ( FD_ISSET(&read_fds, h) ) // std macro
			demux_table.table_[h].event_handler_->handle_event(h, READ_EVENT);
		// perform the same for WRITE_EVENTs and EXCEPT_EVENTs
		}
	}
	Reactor* Select_Reactor_Implementation::instance(){
		return this->instance();
	}


private:
	Demux_Table demux_table;

};