#pragma once

#include "State.h"
#include "StateIdentifiers.h"

#include <vector>
#include <utility>
#include <functional>
#include <map>

class StateStack
{
public:
	enum Action
	{
		Push,
		Pop,
		Clear,
	};
public:
	//!Constructor for a state stack.
	explicit StateStack(State::Context context);

	//!Creates a state.
	template <typename T>
	void registerState(States::ID stateID);

	//!Updates the stack.
	void update(const GameTimer& gt);

	//!Draws everything that was put into each state.
	void draw();

	//!Button event handler.
	void handleEvent(WPARAM btnState);
	void handleRealtimeInput();

	//!Pushes a state into the stack.
	void pushState(States::ID stateID);
	//!Remove a state from the stack.
	void popState();

	//!Clears stack.
	void clearStates();

	bool isEmpty() const;

	XMFLOAT3 getCameraPos();
	XMFLOAT3 getTargetPos();
	State* getCurrentState();
private:
	State::StatePtr createState(States::ID stateID);
	void applyPendingChanges();

private:
	//!Action changelist.
	struct PendingChange
	{
		explicit			PendingChange(Action action, States::ID stateID = States::None);

		Action				action;
		States::ID			stateID;
	};

private:
	//!State stack.
	std::vector<State::StatePtr>	mStack;

	//!Command queue list.
	std::vector<PendingChange>	mPendingList;

	//!Context.
	State::Context	mContext;

	//!State factory.
	std::map<States::ID, std::function<State::StatePtr()>> mFactories;
};


template <typename T>
void StateStack::registerState(States::ID stateID)
{
	mFactories[stateID] = [this]()
	{
		return State::StatePtr(new T(this, &mContext));
	};
}

