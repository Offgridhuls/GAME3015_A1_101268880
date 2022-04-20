#pragma once

#include "State.h"
#include "World.h"
#include "Player.h"

class GameState :
    public State
{
public:
    GameState(StateStack* stack, Context* context);
    virtual ~GameState();
    virtual void draw()override;
    virtual bool update(const GameTimer& gt)override;
    virtual bool handleEvent(WPARAM btnState)override;
    virtual bool handleRealtimeInput()override;

    void ProcessInput();
private:
    World mWorld;
};

