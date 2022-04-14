#include "GameState.h"
#include "Game.h"

GameState::GameState(StateStack& stack, Context context)
	: State(stack, context)
	, mWorld(this)
	, mPlayer(context.player)
{
	mAllRitems.clear();
	mContext.window->mFrameResources.clear();
	mContext.window->BuildMaterials();

	mWorld.buildScene();
	PRINTF("Game state\n");
	context.window->BuildFrameResources((UINT)mAllRitems.size());
}

void GameState::draw()
{
	mWorld.draw();
}

bool GameState::update(const GameTimer& gt)
{
	mWorld.update(gt);
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer->handleRealtimeInput(commands);

	return true;
}

bool GameState::handleEvent(const Event& event)
{
	CommandQueue& commands = mWorld.getCommandQueue();
	mPlayer->handleEvent(commands);

	return true;
}

void GameState::ProcessInput()
{

}

void GameState::buildScene()
{

}

void GameState::OnKeyDown(WPARAM btnState)
{

}
