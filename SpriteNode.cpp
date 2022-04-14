#include "SpriteNode.h"
#include "Game.h"

SpriteNode::SpriteNode(State* game) : Entity(game)
{
	buildCurrent();
}

void SpriteNode::drawCurrent() const
{
	//mSpriteNodeRitem->World = getWorldTransform();
	//mSpriteNodeRitem->NumFramesDirty++;
}

void SpriteNode::buildCurrent()
{
	//auto render = std::make_unique<RenderItem>();
	renderer = new RenderItem();
	renderer->World = getWorldTransform();
	renderer->ObjCBIndex = mState->getRenderItems().size();
	renderer->Mat = mState->getContext().window->mMaterials["Desert"].get();
	renderer->Geo = mState->getContext().window->mGeometries["shapeGeo"].get();
	renderer->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = renderer->Geo->DrawArgs["grid"].IndexCount;
	renderer->StartIndexLocation = renderer->Geo->DrawArgs["grid"].StartIndexLocation;
	renderer->BaseVertexLocation = renderer->Geo->DrawArgs["grid"].BaseVertexLocation;
	//game->mRitemLayer[(int)RenderLayer::Transparent].push_back(render.get());
	//game->mAllRitems.push_back(std::move(render));
	mState->AddRenderItem(renderer);
}
