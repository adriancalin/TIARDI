#include "stdafx.h"
#include "Event_Log_Demux.h"

typedef std::string::size_type str_size;

Event_Log_Demux::Event_Log_Demux()
{
	
}

Event_Log_Demux::~Event_Log_Demux()
{
	
}

void Event_Log_Demux::handle_log(char in[], int len)
{
	// Delegate based on event type
	char log_type = in[0];
	switch (log_type)
	{
		// Convert buffer to std::string for easier manipulation
		case '1': handle_alarm(std::string(in, 2, len)); break;
		case '2': handle_patient_info(std::string(in, 2, len)); break;
		case '3': handle_simple_log(std::string(in, 2, len)); break;
	}
}   

void Event_Log_Demux::handle_alarm(std::string alarm)
{
	str_size priority_end = alarm.find("|");
	str_size priority_text = alarm.find("|", priority_end + 1);
	std::cout << "Alarm priority: " << alarm.substr(0, priority_end) << std::endl;
	std::cout << "Alarm text: " << alarm.substr(priority_end + 1, priority_text) << std::endl;
}

void Event_Log_Demux::handle_patient_info(std::string patient_info)
{
	str_size type_end = patient_info.find("|");
	str_size value_end = patient_info.find("|", type_end + 1);
	std::cout << "Patient event type: " << patient_info.substr(0, type_end) << std::endl;
	std::cout << "Patient event value: " << patient_info.substr(type_end + 1, value_end) << std::endl;
}

void Event_Log_Demux::handle_simple_log(std::string simple_log)
{
	std::cout << "Log text: " << simple_log << std::endl;
}