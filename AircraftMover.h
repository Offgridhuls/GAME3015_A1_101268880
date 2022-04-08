#pragma once
#include "SceneNode.h"
#include "Common/d3dApp.h"
#include "Aircraft.h"

//! Takes in commands and passes the velocity to the aircraft
struct AircraftMover
{
	
	//! AircraftMover constructor
	AircraftMover(float vx, float vy, float vz) :
		velocity(vx, vy, vz)
	{

	}
	//! Passes in velocity to the aircraft
	void operator() (SceneNode& node, GameTimer) const
	{
		Aircraft& aircraft = static_cast<Aircraft&>(node);
		aircraft.setVelocity(velocity);
	}

    XMFLOAT3 velocity;
};