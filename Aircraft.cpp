#include "Aircraft.h"
#include "Game.h"
#include "State.h"

Aircraft::Aircraft(Type type, State* state) : Entity(nullptr), mType(type), mState(state)
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
	
	renderer = new RenderItem();
	renderer->World = getWorldTransform();
	renderer->ObjCBIndex = mState->getRenderItems().size();
	renderer->Mat = mState->getContext().window->mMaterials[mSprite].get();
	renderer->Geo = mState->getContext().window->mGeometries["shapeGeo"].get();
	renderer->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["grid"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["grid"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["grid"].BaseVertexLocation;
	//game->mRitemLayer[(int)RenderLayer::Transparent].push_back(render.get());
	//game->mAllRitems.push_back(std::move(render));
	mState->AddRenderItem(renderer);
}

unsigned int Aircraft::getCategory() const
{
	switch (mType)
	{
	case Aircraft::Type::Eagle:
		return Category::PlayerAircraft;
		break;
	case Aircraft::Type::Raptor:
		return Category::EnemyAircraft;
		break;
	}
}
