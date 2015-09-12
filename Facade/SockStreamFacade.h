#pragma once
#include <winsock.h>
#include "stdafx.h"
#pragma comment(lib, "ws2_32.lib")

class SockStreamFacade
{
public:
		typedef int ssize_t;
		// Default and copy constructor.
		SockStreamFacade() ;
		SockStreamFacade(SOCKET h);
		// Automatically close the handle on
		~SockStreamFacade();
		// Set/get the underlying SOCKET handle.
		void set_handle(SOCKET h);
		SOCKET get_handle() const;
		// Regular I/O operations.
		ssize_t recv(char *buf, size_t len, int	flags);
		ssize_t send(const char *buf, size_t len, int flags);
		// ... other methods omitted.
	private:
		// Socket handle for exchanging socket data.
		SOCKET handle_;
		typedef int SOCKET;
};

