#pragma once
#include "SceneNode.h"
#include "Aircraft.h"
#include "SpriteNode.h"
#include "CommandQueue.h"
#include "Command.h"


class World
{
public:
	//!World constructor.
	explicit							World(State* state);
	//!Update for world.
	void								update(const GameTimer& gt);
	//!Draws world.
	void								draw();
	//void								loadTextures();
	void								buildScene();

	CommandQueue& getCommandQueue();

private:
	//!World commandqueue.
	CommandQueue						mCommandQueue;


private:

	enum class Layer
	{
		Background,
		Air
	};


private:
	//!Reference to state.
	State* mState;
	//!SceneGraph.
	SceneNode* mSceneGraph;
	std::array<SceneNode*, 2>	mSceneLayers;

	XMFLOAT4							mWorldBounds;
	XMFLOAT2		    				mSpawnPosition;
	float								mScrollSpeed;
	Aircraft* mPlayerAircraft;
	SpriteNode* mBackground;
	SpriteNode* mBackground2;
	Aircraft* mEnemy;
	Aircraft* mEnemy2;
};
