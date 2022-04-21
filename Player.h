#pragma once
#include "Command.h"
#include <map>

class CommandQueue;

class Player
{
public:
	//!Player constructor.
	Player();
	//!Event handler for player.
	void					handleEvent(CommandQueue& commands);

	//!Input handler.
	void					handleRealtimeInput(CommandQueue& commands);

	//!Action enums.
	enum Action
	{
		MoveLeft,
		MoveRight,
		MoveUp,
		MoveDown,
		ActionCount
	};
	//!Assigns action to a key.
	void					assignKey(Action action, char key);

	//!Gets assigned key.
	char					getAssignedKey(Action action) const;
	//!Map keys.
	void remapKeys(int choice);

private:
	//!Init actions.
	void					initializeActions();

	static bool				isRealtimeAction(Action action);

private:
	//!Keybinding map.
	std::map<char, Action>					mKeyBinding;
	//!Actionbinding map.
	std::map<Action, Command>				mActionBinding;
	std::map<char, bool>					mKeyFlag;


};