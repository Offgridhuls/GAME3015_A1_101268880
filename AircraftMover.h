#pragma once
#include "SceneNode.h"
#include "Common/d3dApp.h"
#include "Aircraft.h"

struct AircraftMover
{
	

	AircraftMover(float vx, float vy, float vz) :
		velocity(vx, vy, vz)
	{

	}
	void operator() (SceneNode& node, GameTimer) const
	{
		Aircraft& aircraft = static_cast<Aircraft&>(node);
		aircraft.setVelocity(velocity);
	}

    XMFLOAT3 velocity;

};