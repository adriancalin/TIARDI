#pragma once

class Event_Log_Demux
{
public: 
	Event_Log_Demux();
	~Event_Log_Demux();
	void handle_log(char in[]);

private:
	void handle_alarm(char alarm[]);
	void handle_patient_info(char patient_info[]);
	void handle_simple_log(char simple_log[]);
};