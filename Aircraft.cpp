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
	render->World = getWorldTransform();
	render->ObjCBIndex = game->mAllRitems.size();
	render->Mat = game->mMaterials[mSprite].get();
	render->Geo = game->mGeometries["shapeGeo"].get();
	render->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	render->IndexCount = render->Geo->DrawArgs["grid"].IndexCount;
	render->StartIndexLocation = render->Geo->DrawArgs["grid"].StartIndexLocation;
	render->BaseVertexLocation = render->Geo->DrawArgs["grid"].BaseVertexLocation;
	mAircraftRitem = render.get();
	mRitemLayer[(int)RenderLayer::Transparent].push_back(render.get());
	game->mAllRitems.push_back(std::move(render));
}
