#include "TitleState.h"

TitleState::TitleState(StateStack& stack, Context context)
	: State(stack, context)//, mSceneGraph(new SceneNode(Game* game))
	, mShowText(true)
{

}

void TitleState::draw()
{

}

void TitleState::buildScene()
{

}

bool TitleState::update(const GameTimer& gt)
{
	return true;
}

bool TitleState::handleEvent(const Event& event)
{
	if (event.type == Event::KeyPressed)
	{
		requestStackPop();
		requestStackPush(States::Game);
	}

	return true;
}