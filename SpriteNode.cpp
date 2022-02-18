#include "SpriteNode.h"
#include "Game.h"

SpriteNode::SpriteNode(Game* game) : Entity(game)
{

}

void SpriteNode::drawCurrent() const
{
	//mSpriteNodeRitem->World = getWorldTransform();
	//mSpriteNodeRitem->NumFramesDirty++;
}

void SpriteNode::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	renderer = render.get();
	renderer->World = getWorldTransform();
	XMStoreFloat4x4(&render->TexTransform, XMMatrixScaling(1.0f, 1.0f, 1.0f));
	renderer->ObjCBIndex = game->mAllRitems.size();
	renderer->Mat = game->mMaterials["Desert"].get();
	renderer->Geo = game->mGeometries["shapeGeo"].get();
	renderer->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	renderer->IndexCount = render->Geo->DrawArgs["grid"].IndexCount;
	renderer->StartIndexLocation = render->Geo->DrawArgs["grid"].StartIndexLocation;
	renderer->BaseVertexLocation = render->Geo->DrawArgs["grid"].BaseVertexLocation;
	game->mRitemLayer[(int)RenderLayer::Opaque].push_back(render.get());
	game->mAllRitems.push_back(std::move(render));
}
