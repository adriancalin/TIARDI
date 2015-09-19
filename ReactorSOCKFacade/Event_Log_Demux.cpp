#include "stdafx.h"
#include "Event_Log_Demux.h"


Event_Log_Demux::Event_Log_Demux()
{
	
}

Event_Log_Demux::~Event_Log_Demux()
{
	
}

void Event_Log_Demux::handle_log(char in[], int len)
{
	char log_type = in[0];
	switch (log_type)
	{
		case '1': handle_alarm(std::string(in, 2, len)); break;
		case '2': handle_patient_info(std::string(in, 2, len)); break;
		case '3': handle_simple_log(std::string(in, 2, len)); break;
	}
}   

void Event_Log_Demux::handle_alarm(std::string alarm)
{
	typedef std::string::size_type str_size;
	str_size priority_end = alarm.find("|");
	str_size priority_text = alarm.find("|", priority_end + 1);
	std::cout << "Alarm priority: " << alarm.substr(0, priority_end) << std::endl;
	std::cout << "Alarm text: " << alarm.substr(priority_end + 1, priority_text) << std::endl;
}

void Event_Log_Demux::handle_patient_info(std::string patient_info)
{
	std::cout << "Event_Log_Demux->got patient_info=" << patient_info << std::endl;
}

void Event_Log_Demux::handle_simple_log(std::string simple_log)
{
	std::cout << "Event_Log_Demux->got simple_log=" << simple_log << std::endl;
}