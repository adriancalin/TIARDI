#pragma once

#include <string>

class Event_Log_Demux
{
public: 
	Event_Log_Demux();
	~Event_Log_Demux();
	std::string handle_log(std::string);

private:
	std::string get_info(std::string);
	std::string insert_info(std::string);
};