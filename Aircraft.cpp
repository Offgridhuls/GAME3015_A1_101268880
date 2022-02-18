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
	renderer = render.get();
	renderer->World = getWorldTransform();
	renderer->ObjCBIndex = game->mAllRitems.size();
	renderer->Mat = game->mMaterials[mSprite].get();
	renderer->Geo = game->mGeometries["shapeGeo"].get();
	renderer->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = render->Geo->DrawArgs["grid"].IndexCount;
	renderer->StartIndexLocation = render->Geo->DrawArgs["grid"].StartIndexLocation;
	renderer->BaseVertexLocation = render->Geo->DrawArgs["grid"].BaseVertexLocation;
	game->mRitemLayer[(int)RenderLayer::Transparent].push_back(render.get());
	game->mAllRitems.push_back(std::move(render));
}
