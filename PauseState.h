#pragma once
#include "State.h"

class PauseState : public State
{
public:
    PauseState(StateStack* stack, Context* context);
    virtual ~PauseState();
    virtual void draw()override;
    virtual bool update(const GameTimer& gt)override;
    virtual bool handleEvent(WPARAM btnState)override;
    virtual bool handleRealtimeInput()override;

};