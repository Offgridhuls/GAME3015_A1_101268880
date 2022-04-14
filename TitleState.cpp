#include "TitleState.h"
#include "Game.h"

TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context) , mSceneGraph(new SceneNode(this))
	, mShowText(true)
{
	mAllRitems.clear();
	mContext.window->mFrameResources.clear();
	mContext.window->BuildMaterials();
	
	std::unique_ptr<SpriteNode> backgroundSprite = std::make_unique<SpriteNode>(this);
	backgroundSprite->setWorldPosition(0.0, -10.0, 40);
	mSceneGraph->attachChild(std::move(backgroundSprite));

	PRINTF("Building frame resources with size: %i\n", mAllRitems.size());
	context.window->BuildFrameResources((UINT)mAllRitems.size());
}

void TitleState::draw()
{
	mSceneGraph->draw();
}

void TitleState::buildScene()
{
	
}

bool TitleState::update(const GameTimer& gt)
{
	mSceneGraph->Update(gt);
	return true;
}

bool TitleState::handleEvent(const Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::ID::Game);
	}

	return true;
}

void TitleState::ProcessInput()
{

}

void TitleState::OnKeyDown(WPARAM btnState)
{
	requestStackPop();
	requestStackPush(States::ID::Game);

}
