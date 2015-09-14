#pragma once
#include <winsock.h>
typedef int Handle;
typedef const timeval Time_Value;
typedef unsigned int Event_Type; 
enum{
	READ_EVENT = 01,
	ACCEPT_EVENT = 01,
	WRITE_EVENT = 02,
	TIMEOUT_EVENT = 04,
	SIGNAL_EVENT = 010,
	CLOSE_EVENT = 020
};
class Alarm_Event{
public:
	int priority;
	char text[30];
};
class Patient_Value_Event{
public:
	int type;
	char value[50];
};
class Log_Event{
public:
	char text[50];
};