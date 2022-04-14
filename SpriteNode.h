#pragma once
#include "Entity.h"
#include "SceneNode.h"

class State;

//! Spritenode class, inherits Entity.
class SpriteNode : public Entity
{

public:
	//! Sprite node constructor.
	SpriteNode(State* game);

	//! Is an item that is rendered into the scene.
	RenderItem* mSpriteNodeRitem;

	//std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];
private:
	//! Does nothing.
	virtual void drawCurrent() const;

	//! Builds the node.
	virtual void buildCurrent();
};

