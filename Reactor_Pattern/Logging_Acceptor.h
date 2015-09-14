#pragma once
#include "Event_Handler.h"
#include "SOCK_Stream.h"
#include "Reactor.h"
#include "Logging_Handler.h"
#include "SOCK_Acceptor.h"

class Logging_Acceptor : public Event_Handler {
public:
	public:
	Logging_Acceptor (INET_Addr &addr, Reactor *reactor):
	acceptor_ (addr), reactor_ (reactor) {
		reactor_->register_handler (this, ACCEPT_EVENT);
	}
	virtual void handle_event(Handle, Event_Type event_type) {
		// Can only be called for an ACCEPT event.
		if (event_type == ACCEPT_EVENT) {
			SOCK_Stream client_connection;
			// Accept the connection.
			acceptor_.accept(client_connection);
			// Create a new <Logging_Handler>.
			Logging_Handler *handler = new Logging_Handler (client_connection, reactor_);
		}
	}
	virtual Handle Logging_Acceptor::get_handle() const {
		return acceptor_.get_handle ();
	}
private:
	// Socket factory that accepts client connections.
	SOCK_Acceptor acceptor_;
	// Cached <Reactor>.
	Reactor *reactor_;
};