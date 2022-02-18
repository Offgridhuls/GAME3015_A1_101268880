#pragma once
#include "Entity.h"
#include "SceneNode.h"
#include <string>
class Aircraft : public Entity
{
public:

	enum class Type
	{
		Eagle,
		Raptor,
	};

	Aircraft(Type type, Game* game);

private:
	Type mType;
	std::string mSprite;

	std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	virtual void drawCurrent() const;
	virtual void buildCurrent();
	RenderItem* mAircraftRitem;
};

