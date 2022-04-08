#pragma once

#include "Command.h"

#include <queue>

//! Handles the command queue
class CommandQueue
{
public:
	//! Pushed command into queue
	void push(const Command& command);

	//! Takes command out of queue for use
	Command pop();

	//! Checks if queue is empty
	bool isEmpty() const;

private:

	std::queue<Command> mQueue;
};

