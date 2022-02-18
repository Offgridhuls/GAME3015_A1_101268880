#include "SpriteNode.h"
#include "Game.h"

SpriteNode::SpriteNode(Game* game) : Entity(game)
{

}

void SpriteNode::drawCurrent() const
{
	//render->World = getWorldTransform();
	//render->NumFramesDirty++;
}

void SpriteNode::buildCurrent()
{
	auto render = std::make_unique<RenderItem>();
	render->World = getWorldTransform();
	XMStoreFloat4x4(&render->TexTransform, XMMatrixScaling(10.0f, 10.0f, 10.0f));
	render->Mat = game->mMaterials["Desert"].get();
	render->Geo = game->mGeometries["shapeGeo"].get();
	render->PrimitiveType = D3D10_PRIMITIVE_TOPOLOGY_TRIANGLELIST;
	render->IndexCount = render->Geo->DrawArgs["grid"].IndexCount;
	render->StartIndexLocation = render->Geo->DrawArgs["grid"].StartIndexLocation;
	render->BaseVertexLocation = render->Geo->DrawArgs["grid"].BaseVertexLocation;
	//render->NumFramesDirty++;
	mSpriteNodeRitem = render.get();
	mRitemLayer[(int)RenderLayer::Opaque].push_back(render.get());
	game->mAllRitems.push_back(std::move(render));
}
