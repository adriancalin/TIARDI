#include "stdafx.h"
#include "SockStreamFacade.h"
#include <winsock.h>
#pragma comment(lib, "ws2_32.lib")


SockStreamFacade::SockStreamFacade() : handle_(-1)
{
}

SockStreamFacade::SockStreamFacade(::SOCKET h) : handle_(h)
{
}

SockStreamFacade::~SockStreamFacade()
{
	closesocket(handle_);
}

void SockStreamFacade::set_handle(::SOCKET h)
{
	handle_ = h;
}

SOCKET SockStreamFacade::get_handle() const
{
	return handle_;
}

size_t SockStreamFacade::recv(void* buf, size_t len, int flags)
{
	return recv(buf, len, flags);
}

size_t SockStreamFacade::send(const char* buf, size_t len, int flags)
{
	return send(buf, len, flags);
}

size_t SockStreamFacade::recv_n(char* buf, size_t len, int flags)
{
	return recv_n(buf, len, flags);
}

size_t SockStreamFacade::send_n(const char* buf, size_t len, int flags)
{
	return send_n(buf, len, flags);
}