#pragma once
#include "Entity.h"
#include "SceneNode.h"
class Aircraft : public Entity
{
public:

	enum Type
	{
		Eagle,
		Raptor,
	};

	Aircraft(Type type, Game* game);

private:
	Type mType;
	std::string mSprite;

	virtual void drawCurrent() const;
	virtual void buildCurrent();
};

