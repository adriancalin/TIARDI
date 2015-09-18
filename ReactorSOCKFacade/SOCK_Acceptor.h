#pragma once

#include "stdafx.h"
#include "sock_lib.h"


class SOCK_Acceptor
{
public:
	SOCK_Acceptor(INET_Addr &addr);
	~SOCK_Acceptor();
	void open(const INET_Addr &sock_addr);
	void accept(SOCK_Stream &s);
	SOCKET get_handle() const;
private:
	SOCKET handle_;
};


