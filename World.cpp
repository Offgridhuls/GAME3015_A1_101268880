#define NOMINMAX
#include "World.h"

World::World(State* state)
	: mSceneGraph(new SceneNode(state))
	, mState(state)
	, mPlayerAircraft(nullptr)
	, mBackground(nullptr)
	, mWorldBounds(-120.0f, 120.0f, 30.0f, 0.0f)
	, mSpawnPosition(0.f, 0.f)
	, mScrollSpeed(5.0f)
{
}

void World::update(const GameTimer& gt)
{
	mPlayerAircraft->setVelocity(0.0f, 0.0f, 0.0f);
	while (!mCommandQueue.isEmpty())
		mSceneGraph->onCommand(mCommandQueue.pop(), gt);

	mSceneGraph->update(gt);

	XMFLOAT3 enemyVelocity = mEnemy->getVelocity();
	XMFLOAT3 enemyPosition = mEnemy->getWorldPosition();
	XMFLOAT3 enemy2Position = mEnemy2->getWorldPosition();
	XMFLOAT3 backgroundPosition = mBackground->getWorldPosition();
	XMFLOAT3 background2Position = mBackground2->getWorldPosition();

	if (enemy2Position.x > 0.5f)
	{
		//playerVelocity.x = -playerVelocity.x;
		//mPlayerAirCraft->setVelocity(playerVelocity);
		enemyVelocity.x = -enemyVelocity.x;
		mEnemy->setVelocity(enemyVelocity);
		mEnemy2->setVelocity(enemyVelocity);
	}

	else if (enemyPosition.x < -0.5f)
	{
		//playerVelocity.x = -playerVelocity.x;
		//mPlayerAirCraft->setVelocity(playerVelocity);
		enemyVelocity.x = -enemyVelocity.x;
		mEnemy->setVelocity(enemyVelocity);
		mEnemy2->setVelocity(enemyVelocity);
	}

	if (backgroundPosition.z < mWorldBounds.w - 15)
	{
		mBackground->setPosition(0.0, 0.0, 15.0);
	}

	if (background2Position.z < mWorldBounds.w - 15)
	{
		mBackground2->setPosition(0.0, 0.0, 15.0);
	}
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
	mPlayerAircraft->setPosition(0.0f, 6.5f, 1.0f);
	mPlayerAircraft->setScale(0.5f, 0.5f, 0.5f);
	mPlayerAircraft->setWorldRotation(0.3f, 0.0f, 0.0f);
	mPlayerAircraft->setVelocity(mScrollSpeed, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(player));

	std::unique_ptr<Aircraft> enemy1(new Aircraft(Aircraft::Type::Raptor, mState));
	mEnemy = enemy1.get();
	mEnemy->setPosition(0.5f, 6.5f, 0.0f);
	mEnemy->setScale(0.5f, 0.5f, 0.5f);
	mEnemy->setVelocity(-1, 0, 0);
	mEnemy->setWorldRotation(0.3f, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(enemy1));

	std::unique_ptr<Aircraft> enemy2(new Aircraft(Aircraft::Type::Raptor, mState));
	mEnemy2 = enemy2.get();
	mEnemy2->setPosition(-0.5f, 6.5f, 0.0f);
	mEnemy2->setScale(0.5f, 0.5f, 0.5f);
	mEnemy2->setVelocity(-1, 0, 0);
	mEnemy2->setWorldRotation(0.3f, 0.0f, 0.0f);
	mSceneGraph->attachChild(std::move(enemy2));

	std::unique_ptr<SpriteNode> backgroundSprite(new SpriteNode(mState));
	backgroundSprite->SetMatGeoDrawName("Desert", "shapeGeo", "box");
	mBackground = backgroundSprite.get();
	mBackground->setPosition(0, 0, 0.0);
	mBackground->setScale(15.0, 1.0, 15.0);
	mBackground->setVelocity(0, 0, -mScrollSpeed);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	std::unique_ptr<SpriteNode> backgroundSprite2(new SpriteNode(mState));
	backgroundSprite2->SetMatGeoDrawName("Desert", "shapeGeo", "box");
	mBackground2 = backgroundSprite2.get();
	mBackground2->setPosition(0, 0, 15.0);
	mBackground2->setScale(15.0, 1.0, 15.0);
	mBackground2->setVelocity(0, 0, -mScrollSpeed);
	mSceneGraph->attachChild(std::move(backgroundSprite2));

	mSceneGraph->build();
}
