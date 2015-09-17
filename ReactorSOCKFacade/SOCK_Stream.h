#pragma once

#include "stdafx.h"

class SOCK_Stream
{
public:
	SOCK_Stream();
	SOCK_Stream(SOCKET h);
	~SOCK_Stream();
	void set_handle(SOCKET h);
	SOCKET get_handle() const;
	SSIZE_T recv(char *buf, size_t len, int	flags);
	SSIZE_T send(const char *buf, size_t len, int flags);

private:
	SOCKET handle_;
};
