#pragma once
#include <iostream>
#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	Entity(Game* game);

	void setVelocity(XMFLOAT3 velocity);
	void setVelocity(float vx, float vy, float vz);
	void setSpeed(float speed);

	XMFLOAT3 getVelocity() const;
	float getSpeed();

	virtual void updateCurrent(GameTimer dt);

	XMFLOAT3 mVelocity;
	float mSpeed;
};

