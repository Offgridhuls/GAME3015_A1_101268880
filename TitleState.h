#pragma once
#include "State.h"
class TitleState :
    public State
{
public:
    //!Titlestate constructor.
    TitleState(StateStack* stack, Context* context);
    virtual ~TitleState();

    //!Draw function of state.
    virtual void draw()override;

    //!Updates state.
    virtual bool update(const GameTimer& gt)override;

    //!Event handler.
    virtual bool handleEvent(WPARAM btnState)override;
    virtual bool handleRealtimeInput()override;

};

