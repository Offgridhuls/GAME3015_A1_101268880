#pragma once
#include "Entity.h"
#include "SceneNode.h"
#include <string>
class Aircraft : public Entity //Aircraft class, inherits Entity.
{
public:

	enum class Type //Enum of type of aircraft in which we need to spawn.
	{
		Eagle,
		Raptor,
	};

	Aircraft(Type type, Game* game); //Aircraft constructor.

private:
	Type mType; //Type of aircraft.
	std::string mSprite; //Sprite of aircraft.

	//std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	virtual void drawCurrent() const; //Does nothing.
	virtual void buildCurrent(); //Builds the current aircraft.
	RenderItem* mAircraftRitem; //Reference to a render item.
};

