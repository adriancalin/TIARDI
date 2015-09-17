#pragma once

#include "stdafx.h"
#include "sock_facade.h"


class SOCK_Acceptor
{
public:
	SOCK_Acceptor(INET_Addr &addr);
	~SOCK_Acceptor();
	void open(const INET_Addr &sock_addr);
	void accept(SOCK_Stream &s);

private:
	SOCKET handle_;
};


