#pragma once
#include "State.h"

class PauseState : public State
{
public:
    PauseState(StateStack* stack, Context* context);
    virtual ~PauseState();

    //!Draw function for state.
    virtual void draw()override;

    //!Update function for state.
    virtual bool update(const GameTimer& gt)override;

    //!Event handler.
    virtual bool handleEvent(WPARAM btnState)override;
    virtual bool handleRealtimeInput()override;

};