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
	virtual void ProcessInput();
	virtual void buildScene();
	virtual void OnKeyDown(WPARAM btnState)override;
private:
	World mWorld;
	Player* mPlayer;
};