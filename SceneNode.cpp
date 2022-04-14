#include "SceneNode.h"
#include "Command.h"

SceneNode::SceneNode(State* state) //Scenenode Constructor
	: mChildren(),
      mParent(nullptr),
      mState(state)
{
	mWorldPosition = XMFLOAT3(0, 0, 0); //Scenenode declaration for WorldPosition
	mWorldScaling = XMFLOAT3(1, 1, 1);  //Scenenode declaration for WorldScaling
	mWorldRotation = XMFLOAT3(0, 0, 0); //Scenenode declaration for WorldRotation
}

void SceneNode::attachChild(Ptr child) //Attaches specified child to parent object.
{
	child->mParent = this;
	mChildren.push_back(std::move(child));
}

SceneNode::Ptr SceneNode::detachChild(const SceneNode& node) //Detaches specified child from parent object.
{
	auto found = std::find_if(mChildren.begin(), mChildren.end(), [&](Ptr& p) {return p.get() == &node; });
	assert(found != mChildren.end());

	Ptr result = std::move(*found);
	mChildren.erase(found);
	return result;
}

void SceneNode::Update(const GameTimer& dt) //Update function of Scenenode.
{
	updateCurrent(dt);
	updateChildren(dt);
}

void SceneNode::move(float x, float y, float z) //Move function of Scenenode-moves object by velocity.
{
	mWorldPosition.x += x;
	mWorldPosition.y += y;
	mWorldPosition.z += z;
}

XMFLOAT3 SceneNode::getWorldPosition() const //Get world position returns mWorldPosition.
{
	return mWorldPosition;
}

void SceneNode::setWorldPosition(float x, float y, float z) //Sets world position.
{
	mWorldPosition = XMFLOAT3(x, y, z);
}

XMFLOAT3 SceneNode::getWorldRotation() const // Get world rotation.
{
	return mWorldRotation;
}

void SceneNode::setWorldRotation(float x, float y, float z) //Set world rotation.
{
	mWorldRotation = XMFLOAT3(x, y, z);
}

XMFLOAT3 SceneNode::getWorldScale() const //Get world scale.
{
	return mWorldScaling;
}

void SceneNode::setWorldScale(float x, float y, float z) //Set world scale.
{
	mWorldScaling = XMFLOAT3(x, y, z);
}

XMFLOAT4X4 SceneNode::getWorldTransform() const //Gets world orientation. 
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

XMFLOAT4X4 SceneNode::getTransform() const //Gets transform of object.
{
	XMFLOAT4X4 transform;
	XMMATRIX T(XMMatrixTranslation(mWorldPosition.x, mWorldPosition.y, mWorldPosition.z) * XMMatrixRotationX(XMConvertToRadians(mWorldRotation.x)) *
		XMMatrixRotationY(XMConvertToRadians(mWorldRotation.y)) *
			XMMatrixRotationZ(XMConvertToRadians(mWorldRotation.z)) * 
				XMMatrixScaling(mWorldScaling.x, mWorldScaling.y, mWorldScaling.z));

	XMStoreFloat4x4(&transform, T);

	return transform;
}


void SceneNode::updateChildren(GameTimer dt) //Updates children.
{
	for(Ptr& child : mChildren)
	{
		child->Update(dt);
	}
}

void SceneNode::drawCurrent() const //Does nothing.
{
	
}

void SceneNode::drawChildren() const //Draws children
{
	for(const Ptr& child : mChildren)
	{
		child->draw();
	}
}

void SceneNode::buildCurrent() //Does nothing.
{

}

void SceneNode::buildChildren() //Builds Children.
{
	for(const Ptr& child : mChildren)
	{
		child->build();
	}
}

void SceneNode::draw() const //Draws Scenenode children.
{
	drawChildren();
	drawCurrent();
}

void SceneNode::build() //Builds Scenenode children.
{
	buildCurrent();
	buildChildren();
}

void SceneNode::updateCurrent(GameTimer dt)
{
	//Do nothing here
}

void SceneNode::onCommand(const Command& command, GameTimer dt)
{
	// Command current node, if category matches
	if (command.category & getCategory())
	{
		command.action(*this, dt);
	}

	// Command children
	for (Ptr& child : mChildren)
	{
		child->onCommand(command, dt);
	}
}

unsigned int SceneNode::getCategory() const
{
	return Category::Scene;
}



