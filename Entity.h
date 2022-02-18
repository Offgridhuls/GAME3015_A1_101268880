#pragma once
#include <iostream>
#include "SceneNode.h"

//! Entity class, inherits Scenenode.
class Entity : public SceneNode
{
public:
	//! Entity constructor.
	Entity(Game* game);

	//! Sets velocity of Entity. 
	void setVelocity(XMFLOAT3 velocity);

	//! Sets individual velocity float params. (X, Y, Z)
	void setVelocity(float vx, float vy, float vz);

	//! Sets speed of Entity.
	void setSpeed(float speed);

	//! Returns velocity of Entity.
	XMFLOAT3 getVelocity() const;

	//! Returns speed of Entity.
	float getSpeed();

	//! Update the Entity object.
	virtual void updateCurrent(GameTimer dt);

	//! Variable for velocity.
	XMFLOAT3 mVelocity;

	//! Variable for speed.
	float mSpeed;
};

