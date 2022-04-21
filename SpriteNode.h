#pragma once
#include "Entity.h"


class SpriteNode :
	public Entity
{
public:
	//!SpriteNode Constructor.
	SpriteNode(State* state);
	RenderItem* mSpriteNodeRitem;

	//!Sets draw parameters.
	void SetMatGeoDrawName(std::string Mat, std::string Geo, std::string DrawName);

private:
	//!Draws current node.
	virtual void		drawCurrent() const;
	//!Builds current node.
	virtual void		buildCurrent();

	std::string mMat;
	std::string mGeo;
	std::string mDrawName;
};
