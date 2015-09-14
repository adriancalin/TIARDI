#pragma once
#include "stdafx.h"
#include "SOCK_Stream.h"
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")

typedef int ssize_t;
SOCK_Stream::SOCK_Stream() : handle_(-1)
{
}

SOCK_Stream::SOCK_Stream(::SOCKET h) : handle_(h)
{
	handle_ = h;
}

SOCK_Stream::~SOCK_Stream()
{
	closesocket(handle_);
}

void SOCK_Stream::set_handle(::SOCKET h)
{
	handle_ = h;
}

SOCKET SOCK_Stream::get_handle() const
{
	return handle_;
}

ssize_t SOCK_Stream::recv(char* buf, size_t len, int flags)
{
	return _WINSOCKAPI_::recv(handle_,buf, len, flags);
}

ssize_t SOCK_Stream::send(const char* buf, size_t len, int flags)
{
	return _WINSOCKAPI_::send(handle_,buf, len, flags);
}