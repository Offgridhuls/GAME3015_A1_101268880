#pragma once

#include "State.h"
#include "World.h"
#include "Player.h"

class GameState :
    public State
{
public:
    //!Gamestate constructor.
    GameState(StateStack* stack, Context* context);
    virtual ~GameState();

    //!Draws in state.
    virtual void draw()override;

    //!Updates state.
    virtual bool update(const GameTimer& gt)override;
    //!Handles state events.
    virtual bool handleEvent(WPARAM btnState)override;
    //!Handles input.
    virtual bool handleRealtimeInput()override;
    //!Process input.
    void ProcessInput();
private:
    World mWorld;
};

