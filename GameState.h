#pragma once

#include "State.h"
#include "World.h"
#include "Player.h"

class GameState : public State
{
public:
	GameState(StateStack& stack, Context context);

	virtual void draw();
	virtual bool update(const GameTimer& gt);
	virtual bool handleEvent(const Event& event);

private:
	World mWorld;
	Player* mPlayer;
};