#define NOMINMAX
#include "World.h"

World::World(State* state)
	: mSceneGraph(new SceneNode(state))
	, mState(state)
	, mPlayerAircraft(nullptr)
	, mBackground(nullptr)
	, mWorldBounds(-4.25f, 4.25f, -3.0f, 3.0f) //Left, Right, Down, Up
	, mSpawnPosition(0.f, 0.f)
	, mScrollSpeed(1.0f)
{
}

void World::update(const GameTimer& gt)
{
	mPlayerAircraft->setVelocity(0.0f, 0.0f, 0.0f);
	while (!mCommandQueue.isEmpty())
		mSceneGraph->onCommand(mCommandQueue.pop(), gt);

	mSceneGraph->update(gt);
}

CommandQueue& World::getCommandQueue()
{
	return mCommandQueue;
}

void World::draw()
{
	mSceneGraph->draw();
}

void World::buildScene()
{
	std::unique_ptr<Aircraft> player(new Aircraft(Aircraft::Type::Eagle, mState));
	mPlayerAircraft = player.get();
	mPlayerAircraft->setPosition(0.0f, 6.0f, 1.0f);
	mPlayerAircraft->setScale(0.5f, 0.5f, 0.5f);
	mPlayerAircraft->setWorldRotation(0.3f, 0.0f, 0.0f);
	mPlayerAircraft->setVelocity(mScrollSpeed, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Aircraft> enemy1(new Aircraft(Aircraft::Type::Raptor, mState));
	auto raptor = enemy1.get();
	raptor->setPosition(1.5f, 6.0f, 0.0f);
	raptor->setScale(0.5f, 0.5f, 0.5f);
	raptor->setWorldRotation(0.3f, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(enemy1));

	std::unique_ptr<Aircraft> enemy2(new Aircraft(Aircraft::Type::Raptor, mState));
	auto raptor2 = enemy2.get();
	raptor2->setPosition(-1.5f, 6.0f, 0.0f);
	raptor2->setScale(0.5f, 0.5f, 0.5f);
	raptor2->setWorldRotation(0.3f, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mState));
	backgroundSprite->SetMatGeoDrawName("Desert", "shapeGeo", "box");
	mBackground = backgroundSprite.get();
	//mBackground->setPosition(mWorldBounds.left, mWorldBounds.top);
	mBackground->setPosition(0, 0, 0.0);
	mBackground->setScale(200.0, 1.0, 200.0);
	mBackground->setVelocity(0, 0, -mScrollSpeed);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	mSceneGraph->build();
}
