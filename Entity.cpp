#include "Entity.h"
Entity::Entity(Game* game) : SceneNode(game), mVelocity(0,0,0)
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
	XMFLOAT2 mV;

	mV.x = mVelocity.x * dt.DeltaTime() * mSpeed;
	mV.y = mVelocity.y * dt.DeltaTime() * mSpeed;

	move(mV.x, mV.y, 0);

	renderer->World = getWorldTransform();
	renderer->NumFramesDirty++;
}
