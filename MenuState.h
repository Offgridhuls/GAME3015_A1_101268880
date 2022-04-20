#pragma once
#include "State.h"

class MenuState : public State
{
public:
    MenuState(StateStack* stack, Context* context);
    virtual ~MenuState();
    virtual void draw()override;
    virtual bool update(const GameTimer& gt)override;
    virtual bool handleEvent(WPARAM btnState)override;
    virtual bool handleRealtimeInput()override;
};