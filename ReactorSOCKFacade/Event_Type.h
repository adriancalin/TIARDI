#pragma once

#include "stdafx.h"

typedef SOCKET Handle;

typedef const timeval Time_Value;

typedef unsigned int Event_Type;

enum {
	READ_EVENT = 01,
	ACCEPT_EVENT = 01,
	WRITE_EVENT = 02,
	TIMEOUT_EVENT = 04,
	SIGNAL_EVENT = 010,
	CLOSE_EVENT = 020
};