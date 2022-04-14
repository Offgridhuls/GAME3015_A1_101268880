#include "Entity.h"
#include "State.h"


Entity::Entity(State* state) : SceneNode(state), mVelocity(0,0,0)
{
	
}

void Entity::setVelocity(XMFLOAT3 velocity)
{
	mVelocity = velocity;
}

void Entity::setSpeed(float speed)
{
	mSpeed = speed;
}

void Entity::setVelocity(float vx, float vy, float vz)
{
	mVelocity.x = vx;
	mVelocity.y = vy;
	mVelocity.z = vz;
}

XMFLOAT3 Entity::getVelocity() const
{
	return mVelocity;
}

float Entity::getSpeed()
{
	return mSpeed;
}

void Entity::updateCurrent(GameTimer dt)
{
	XMFLOAT3 mV;

	mV.x = mVelocity.x * dt.DeltaTime() * mSpeed;
	mV.y = mVelocity.y * dt.DeltaTime() * mSpeed;
	mV.z = mVelocity.z * dt.DeltaTime() * mSpeed;

	move(mV.x, mV.y, mV.z);

	renderer->World = getWorldTransform();
	renderer->NumFramesDirty++;
}
