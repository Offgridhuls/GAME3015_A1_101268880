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

	mActionBinding[MoveLeft].action = [](SceneNode& node, GameTimer dt)
	{
		//node.move();
	};
	// Set initial action bindings
	//initializeActions();

	// Assign all categories to player's aircraft
	for (auto& pair : mActionBinding)
		pair.second.category = Category::PlayerAircraft;
}

void Player::handleEvent(CommandQueue& commands)
{
	const float playerSpeed = 30.f;
	//if (GetAsyncKeyState(VK_UP) & 0x8000)
	//{
	//	Command moveLeft;
	//	moveLeft.category = Category::PlayerAircraft;
	//	moveLeft.action = derivedAction<Aircraft>(AircraftMover(-playerSpeed, 0.f, 0.f));
	//	commands.push(moveLeft);
	//}
}

void Player::handleRealtimeInput(CommandQueue& commands)
{
	
}
