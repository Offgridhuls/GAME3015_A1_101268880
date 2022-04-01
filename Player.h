#pragma once
#include "Command.h"
#include "AircraftMover.h"
#include "Keyboard.h"
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

	void assignKey(Action action, Keyboard key);
	Keyboard getAssignedKey(Action action) const;

private:
	void initializeActions();
	static bool isRealtimeAction(Action action);

private:
	XMFLOAT3 playerSpeed;

	std::map<Keyboard, Action>				mKeyBinding;
	std::map<Action, Command>				mActionBinding;
#pragma endregion
};