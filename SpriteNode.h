#pragma once
#include "Entity.h"
#include "SceneNode.h"
class SpriteNode : public Entity
{

public:
	SpriteNode(Game* game);
	RenderItem* mSpriteNodeRitem;

	//std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];
private:
	virtual void drawCurrent() const;
	virtual void buildCurrent();
};

