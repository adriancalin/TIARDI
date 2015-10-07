#include "stdafx.h"
#include "sock_lib.h"
#include "reactor_lib.h"
#include "config.h"
#include <map>
#include <string>

using std::map;		using std::string;

using ::Event_Log;

Event_Log::Event_Log(const SOCK_Stream& stream, Reactor* reactor) : stream_(stream), reactor_(reactor)
{
	
	reactor->register_handler(this, READ_EVENT);
}

Event_Log::~Event_Log() 
{
	std::cout << "Removing handler..." << std::endl;
	reactor_->remove_handler(this, READ_EVENT);
}

void Event_Log::handle_event(Handle handle, Event_Type et)
{

	map<string, string> dummy;
	dummy["1"] = "George Bush";
	dummy["2"] = "Rich Piana";
	dummy["3"] = "Tigan Contrabandist";

	if (et == READ_EVENT)
	{
		char buffer[EVENT_MAX_SIZE];
		int len = stream_.recv(buffer, EVENT_MAX_SIZE, 0);
		if (len <= 0) delete this;
		else
		{
			buffer[len] = '\0';
			const char *response = dummy[string(buffer, 0, len)].c_str();
			stream_.send(response, strlen(response), 0);
//			demux_.handle_log(buffer, len);
		}
		
	}
}

Handle Event_Log::get_handle() const
{
	return stream_.get_handle();
}