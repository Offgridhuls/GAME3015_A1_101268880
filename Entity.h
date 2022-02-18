#pragma once
#include <iostream>
#include "SceneNode.h"

class Entity : public SceneNode
{
public:
	Entity(Game* game);

	void setVelocity(XMFLOAT2 velocity);
	void setVelocity(float vx, float vy);

	XMFLOAT2 getVelocity() const;

	virtual void update(const GameTimer& gt);

	XMFLOAT2 mVelocity;
};

