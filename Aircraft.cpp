#include "Aircraft.h"
#include "Game.h"

Aircraft::Aircraft(Type type, Game* game) : Entity(game), mType(type)
{
	switch (type)
	{
	case (Type::Eagle):
		mSprite = "Eagle";
		break;
	case (Type::Raptor):
		mSprite = "Raptor";
		break;
	default:
		mSprite = "Eagle";
		break;
	}
}

void Aircraft::drawCurrent() const
{

}

void Aircraft::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	mAircraftRitem = render.get();
	mAircraftRitem->World = getWorldTransform();
	mAircraftRitem->ObjCBIndex = game->mAllRitems.size();
	mAircraftRitem->Mat = game->mMaterials[mSprite].get();
	mAircraftRitem->Geo = game->mGeometries["shapeGeo"].get();
	mAircraftRitem->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	mAircraftRitem->IndexCount = render->Geo->DrawArgs["grid"].IndexCount;
	mAircraftRitem->StartIndexLocation = render->Geo->DrawArgs["grid"].StartIndexLocation;
	mAircraftRitem->BaseVertexLocation = render->Geo->DrawArgs["grid"].BaseVertexLocation;
	mRitemLayer[(int)RenderLayer::Transparent].push_back(render.get());
	game->mAllRitems.push_back(std::move(render));
}
