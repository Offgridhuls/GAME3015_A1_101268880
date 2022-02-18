#pragma once
#include "Entity.h"
#include "SceneNode.h"
class SpriteNode : public Entity //Spritenode class, inherits Entity.
{

public:
	SpriteNode(Game* game); //Sprite node constructor.
	RenderItem* mSpriteNodeRitem; //Is an item that is rendered into the scene.

	//std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];
private:
	virtual void drawCurrent() const; //Does nothing.
	virtual void buildCurrent(); //Builds the node.
};

