#pragma once
#include "State.h"

class MenuState : public State
{
public:
    //!Menustate constructor.
    MenuState(StateStack* stack, Context* context);
    virtual ~MenuState();

    //!Draw function for state.
    virtual void draw()override;

    //!Update function for state.
    virtual bool update(const GameTimer& gt)override;

    //!Event handler.
    virtual bool handleEvent(WPARAM btnState)override;

    virtual bool handleRealtimeInput()override;
};