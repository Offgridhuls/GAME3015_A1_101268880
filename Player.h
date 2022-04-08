#pragma once
#include "Command.h"
#include "AircraftMover.h"
#include "Keyboard.h"
#include <map>

class CommandQueue;

//! Player class, handles events and real time input and sends commands to the player game object
class Player
{
public:
	Player();
	//! Handles commands when a key HAS been pressed
	void handleEvent(CommandQueue& commands);

	//! Handles commands when a key IS being pressed
	void handleRealtimeInput(CommandQueue& commands);
#pragma region step 1
	//! Enum for different actions. More can be added
	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		GetPosition,
		ActionCount
	};

	//! Assigns an action to a key
	void assignKey(Action action, Keyboard key);

	//! Returns key binded to passed in action
	Keyboard getAssignedKey(Action action) const;

private:
	//! Initializes player speed and binded actions
	void initializeActions();

	//! Listens for which actions is being called
	static bool isRealtimeAction(Action action);

private:
	XMFLOAT3 playerSpeed;

	std::map<Keyboard, Action>				mKeyBinding;
	std::map<Action, Command>				mActionBinding;
#pragma endregion
};