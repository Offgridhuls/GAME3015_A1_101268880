#include "SceneNode.h"

SceneNode::SceneNode(Game* game)
	: mChildren(),
      mParent(nullptr),
      game(game)
{
	mWorldPosition = XMFLOAT3(0, 0, 0);
	mWorldScaling = XMFLOAT3(1, 1, 1);
	mWorldRotation = XMFLOAT3(0, 0, 0);
}

void SceneNode::attachChild(Ptr child)
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node)
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) {return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	mChildren.erase(found);
	return result;
}

void SceneNode::Update(const GameTimer& dt)
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::move(float x, float y, float z)
{
	mWorldPosition.x += x;
	mWorldPosition.y += y;
	mWorldPosition.z += z;
}

XMFLOAT3 SceneNode::getWorldPosition() const
{
	return mWorldPosition;
}

void SceneNode::setWorldPosition(float x, float y, float z)
{
	mWorldPosition = XMFLOAT3(x, y, z);
}

XMFLOAT3 SceneNode::getWorldRotation() const
{
	return mWorldRotation;
}

void SceneNode::setWorldRotation(float x, float y, float z)
{
	mWorldRotation = XMFLOAT3(x, y, z);
}

XMFLOAT3 SceneNode::getWorldScale() const
{
	return mWorldScaling;
}

void SceneNode::setWorldScale(float x, float y, float z)
{
	mWorldScaling = XMFLOAT3(x, y, z);
}

XMFLOAT4X4 SceneNode::getWorldTransform() const
{
	XMFLOAT4X4 transform = MathHelper::Identity4x4();
	XMMATRIX T = XMLoadFloat4x4(&transform);
	
	for(const SceneNode* node = this; node != nullptr; node = node->mParent)
	{
		XMMATRIX Tp = XMLoadFloat4x4(&node->getTransform());
		T = Tp * T;
	}
	XMStoreFloat4x4(&transform, T);

	return transform;
}

XMFLOAT4X4 SceneNode::getTransform() const
{
	XMFLOAT4X4 transform;
	XMMATRIX T(XMMatrixTranslation(mWorldPosition.x, mWorldPosition.y, mWorldPosition.z) * XMMatrixRotationX(XMConvertToRadians(mWorldRotation.x)) *
		XMMatrixRotationY(XMConvertToRadians(mWorldRotation.y)) *
			XMMatrixRotationZ(XMConvertToRadians(mWorldRotation.z)) * 
				XMMatrixScaling(mWorldScaling.x, mWorldScaling.y, mWorldScaling.z));

	XMStoreFloat4x4(&transform, T);

	return transform;
}


void SceneNode::updateChildren(GameTimer dt)
{
	for(Ptr& child : mChildren)
	{
		child->Update(dt);
	}
}

void SceneNode::drawCurrent() const
{
	
}

void SceneNode::drawChildren() const
{
	for(const Ptr& child : mChildren)
	{
		child->draw();
	}
}

void SceneNode::buildCurrent()
{

}

void SceneNode::buildChildren()
{
	for(const Ptr& child : mChildren)
	{
		child->build();
	}
}

void SceneNode::draw() const
{
	drawChildren();
	drawCurrent();
}

void SceneNode::build()
{
	buildCurrent();
	buildChildren();
}

void SceneNode::updateCurrent(GameTimer dt)
{
	//Do nothing here
}



