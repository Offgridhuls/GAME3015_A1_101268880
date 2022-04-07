#pragma region step 2
#include "Player.h"
#include "CommandQueue.h"
#include "Aircraft.h"

#include <map>
#include <string>
#include <algorithm>
#include <iostream>

Player::Player()
{
	mKeyBinding[Keyboard::Left] = MoveLeft;
	mKeyBinding[Keyboard::Right] = MoveRight;

	// Set initial action bindings
	initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(CommandQueue& commands)
{
	const float playerSpeed = 10.f;
	if (GetAsyncKeyState(Keyboard::Left))
	{
		Command moveLeft;
		moveLeft.category = Category::PlayerAircraft;
		moveLeft.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f, 0.f));
		commands.push(moveLeft);
	}

	else if (GetAsyncKeyState(Keyboard::Right))
	{
		Command moveRight;
		moveRight.category = Category::PlayerAircraft;
		moveRight.action = derivedAction<Aircraft>(AircraftMover(playerSpeed, 0.f, 0.f));
		commands.push(moveRight);
	}

	else
	{
		Command dontMove;
		dontMove.category = Category::PlayerAircraft;
		dontMove.action = derivedAction<Aircraft>(AircraftMover(0.f, 0.f, 0.f));
		commands.push(dontMove);
	}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	for (auto pair : mKeyBinding)
	{
		// If key is pressed, lookup action and trigger corresponding command
		if (GetAsyncKeyState(pair.first) && isRealtimeAction(pair.second))
		commands.push(mActionBinding[pair.second]);
	}
}

void Player::initializeActions()
{

	const float playerSpeed = 200.f;

	mActionBinding[MoveLeft].action = derivedAction<Aircraft>(AircraftMover(-.1f * playerSpeed, .0f, .0f));
	mActionBinding[MoveRight].action = derivedAction<Aircraft>(AircraftMover(.1f * playerSpeed, .0f, .0f));

}

void Player::assignKey(Action action, Keyboard key)
{
	// Remove all keys that already map to action
	for (auto itr = mKeyBinding.begin(); itr != mKeyBinding.end(); )
	{
		if (itr->second == action)
			mKeyBinding.erase(itr++);
		else
			++itr;
	}

	// Insert new binding
	mKeyBinding[key] = action;
}

bool Player::isRealtimeAction(Action action)
{
	switch (action)
	{
	case MoveLeft:
	case MoveRight:
	case MoveDown:
	case MoveUp:
		return true;

	default:
		return false;
	}
}
