#pragma once
#include <iostream>
#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	Entity(Game* game);

	void setVelocity(XMFLOAT2 velocity);
	void setVelocity(float vx, float vy);
	void setSpeed(float speed);

	XMFLOAT2 getVelocity() const;
	float getSpeed();

	virtual void updateCurrent(GameTimer dt);

	XMFLOAT2 mVelocity;
	float mSpeed;
};

