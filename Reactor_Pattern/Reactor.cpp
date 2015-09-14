#include "stdafx.h"
#include "Reactor.h"


void Reactor::register_handler (Event_Handler *eh, Event_Type et){
	Handle handle = eh->get_handle ();
	register_handler(handle, eh, et);
	
}
void Reactor::register_handler (Handle h, Event_Handler *eh, Event_Type et){
	demux_table.table_[h].event_type_ = et;
	demux_table.table_[h].event_handler_ = eh;
}
void Reactor::remove_handler(Event_Handler *eh, Event_Type et){
	Handle handle = eh->get_handle ();
	remove_handler(handle, et);
}
void Reactor::remove_handler(Handle h, Event_Type et){
	demux_table.table_[h].event_type_ = 0;
}
void Reactor::handle_events (Time_Value *timeout){
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
//Reactor* Reactor::instance(){
//	return null;
//}
