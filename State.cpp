#include "State.h"
#include "StateStack.h"
#include "Game.h"
State::Context::Context(Game* window, Player* player)
	: window(window)
	, player(player)
{
}

State::State(StateStack& stack, Context context)
	: mStack(&stack)
	, mContext(context)
{
}

State::~State()
{

}

std::vector<RenderItem*> State::getRenderItems()
{
	return mAllRitems;
}

void State::AddRenderItem(RenderItem* renderItem)
{
	mAllRitems.push_back(renderItem);
}

void State::requestStackPush(States::ID stateID)
{
	mStack->pushState(stateID);
}

void State::requestStackPop()
{
	mStack->popState();
}

void State::requestStateClear()
{
	mStack->clearStates();
}

State::Context State::getContext() const
{
	return mContext;
}
