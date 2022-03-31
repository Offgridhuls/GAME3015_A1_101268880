#pragma once
#include "Command.h"
#include <map>

class CommandQueue;

class Player
{
public:
	Player();
	void handleEvent(CommandQueue& commands);
	void handleRealtimeInput(CommandQueue& commands);
#pragma region step 1
	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		GetPosition,
		ActionCount
	};
	void assignKey(Action action, );
	keyboard key getAssignedKey(Action action) const;

private:
	void initializeActions();
	static bool isRealtimeAction(Action action);

private:

	std::map<Action, Command>				mActionBinding;
#pragma endregion
};