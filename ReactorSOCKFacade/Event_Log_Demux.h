#pragma once

#include <string>

class Event_Log_Demux
{
public: 
	Event_Log_Demux();
	~Event_Log_Demux();
	void handle_log(char in[], int len);

private:
	void handle_alarm(std::string alarm);
	void handle_patient_info(std::string patient_info);
	void handle_simple_log(std::string simple_log);
};