#pragma once
#include <iostream>
#include "SceneNode.h"

class Entity : public SceneNode //Entity class, inherits Scenenode.
{
public:
	Entity(Game* game); //Entity constructor.

	void setVelocity(XMFLOAT3 velocity); //Sets velocity of Entity. 
	void setVelocity(float vx, float vy, float vz); //Sets individual velocity float params. (X, Y, Z)
	void setSpeed(float speed); //Sets speed of Entity.

	XMFLOAT3 getVelocity() const; //Returns velocity of Entity.
	float getSpeed(); //Returns speed of Entity.

	virtual void updateCurrent(GameTimer dt); //Update the Entity object.

	XMFLOAT3 mVelocity; //Variable for velocity.
	float mSpeed; //Variable for speed.
};

