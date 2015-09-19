#include "stdafx.h"
#include "Event_Log_Demux.h"


Event_Log_Demux::Event_Log_Demux()
{
	
}

Event_Log_Demux::~Event_Log_Demux()
{
	
}

void Event_Log_Demux::handle_log(char in[])
{
	char log_type = in[0];
	switch (log_type)
	{
		case '1': printf("Event_Log_Demux->handle alarm\n");
		case '2': printf("Event_Log_Demux->handle patient info\n");
		case '3': printf("Event_Log_Demux->handle simple log\n");
	}
}

void Event_Log_Demux::handle_alarm(char alarm[])
{

}

void Event_Log_Demux::handle_patient_info(char patient_info[])
{

}

void Event_Log_Demux::handle_simple_log(char simple_log[])
{

}