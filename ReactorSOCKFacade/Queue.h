#pragma once

#include "stdafx.h"
#include "reactor_lib.h"
#include <queue>
#include "config.h"

struct QueueMember
{
	Handle handle;
	std::string buffer;
};

class Queue
{
public:
	static Queue* getInstance();
	~Queue();
	bool Enqueue(QueueMember);
	QueueMember Dequeue();
	bool CheckDequeuePossible();
	int GetQueueSize();
private:
	Queue()
	{
	};

	std::queue<QueueMember> queue_;
	int maxItems_ = 10;
	static Queue* instance;
};
