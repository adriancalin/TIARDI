#pragma once
#include "Event_Handler.h"
#include "SOCK_Stream.h"
#include "Reactor.h"
class Logging_Handler:public Event_Handler{
public:
	Logging_Handler (const SOCK_Stream &stream, Reactor *reactor):
	peer_stream_ (stream) {
		reactor->register_handler (this, READ_EVENT);
	}
	
	 virtual void handle_event (Handle, Event_Type event_type) {
		if (event_type == READ_EVENT) {
			//Log_Record log_record;
			//// Code to handle "short-reads" omitted.
			//peer_stream_.recv (&log_record, sizeof log_record);
			//// Write logging record to standard output.
			//log_record.write (STDOUT);
		}
		else if (event_type == CLOSE_EVENT) {
			peer_stream_.close ();
			// Deallocate ourselves.
			delete this;
		}
	}
	virtual Handle get_handle () const {
		return peer_stream_.get_handle ();
	}
private:
	// Receives logging records from a connected client.
	SOCK_Stream peer_stream_;
};