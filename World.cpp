#include "World.h"

World::World(Game* game) : mSceneGraph(new SceneNode(game)), mGame(game),
mPlayerAirCraft(nullptr),
mBackground(nullptr),
mWorldBounds(-1.5f,1.5f,200.0f,0.0f),
mSpawnPosition(0,0),
mScrollSpeed(1.0f)
{

}

void World::update(const GameTimer& gt)
{
	mSceneGraph->Update(gt);
}

void World::draw()
{
	mSceneGraph->draw();
}

void World::buildScene()
{
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Eagle, mGame));
	mPlayerAirCraft = player.get();
	mPlayerAirCraft->setWorldPosition(0.0f, 1.0f, 0.0f);
	mPlayerAirCraft->setWorldScale(.5f, .5f, .5f);

	mSceneGraph->attachChild(std::move(player));
	

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mGame));
	mBackground = backgroundSprite.get();
	mBackground->setWorldPosition(0, 0.0, 0.0);
	mBackground->setWorldScale(10, 1, 200);


	mSceneGraph->build();
}
