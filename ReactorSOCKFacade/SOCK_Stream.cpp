#include "stdafx.h"
#include "sock_lib.h"


SOCK_Stream::SOCK_Stream() : handle_(INVALID_SOCKET)
{
	// Nothing to setup
}

SOCK_Stream::SOCK_Stream(::SOCKET h) : handle_(h)
{
	handle_ = h;
}

SOCK_Stream::~SOCK_Stream()
{
	//closesocket(handle_);
}

void SOCK_Stream::set_handle(::SOCKET h)
{
	handle_ = h;
}

SOCKET SOCK_Stream::get_handle() const
{
	return handle_;
}

SSIZE_T SOCK_Stream::recv(char* buf, size_t len, int flags)
{
	return _WINSOCKAPI_::recv(handle_, buf, len, flags);
}

SSIZE_T SOCK_Stream::send(const char* buf, size_t len, int flags)
{
	return _WINSOCKAPI_::send(handle_, buf, len, flags);
}
