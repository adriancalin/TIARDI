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
		case '1': handle_alarm(std::string(in, 2, len));
		case '2': handle_patient_info(std::string(in, 2, len));
		case '3': handle_simple_log(std::string(in, 2, len));
	}
}   

void Event_Log_Demux::handle_alarm(std::string alarm)
{
	std::cout << "Event_Log_Demux->got alarm=" << alarm << std::endl;
}

void Event_Log_Demux::handle_patient_info(std::string patient_info)
{
	std::cout << "Event_Log_Demux->got patient_info=" << patient_info << std::endl;
}

void Event_Log_Demux::handle_simple_log(std::string simple_log)
{
	std::cout << "Event_Log_Demux->got simple_log=" << simple_log << std::endl;
}