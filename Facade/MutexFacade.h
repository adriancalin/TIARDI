#pragma once
#include <windows.h>
#pragma comment(lib, "ws2_32.lib")

class MutexFacade
{
public:
	MutexFacade();
	~MutexFacade();
	void aquire();
	void release();
private:
	// Win32-specific Mutex mechanism.
	CRITICAL_SECTION mutex_;
	// Disallow copying and assignment.
	MutexFacade(const MutexFacade &);
	void operator= (const MutexFacade &);
};

