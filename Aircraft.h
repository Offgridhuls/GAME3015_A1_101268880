#pragma once
#include "Entity.h"
#include "SceneNode.h"
#include <string>


//! Aircraft class, inherits Entity.
class Aircraft : public Entity
{
public:
	//! Enum of type of aircraft in which we need to spawn.
	enum class Type
	{
		Eagle,
		Raptor,
	};

	//! Aircraft constructor.
	Aircraft(Type type, State* state);
	virtual unsigned int getCategory() const;

private:
	//! Type of aircraft.
	Type mType;

	//! Sprite of aircraft.
	std::string mSprite;

	//std::vector<RenderItem*> mRitemLayer[(int)RenderLayer::Count];

	 //! Does nothing.
	virtual void drawCurrent() const;

	//! Builds the current aircraft.
	virtual void buildCurrent();

	//! Reference to a render item.
	RenderItem* mAircraftRitem;
};

