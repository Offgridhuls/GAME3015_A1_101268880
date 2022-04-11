#ifndef BOOK_STATESTACK_H
#define BOOK_STATESTACK_H

#include "State.h"
#include "StateIdentifiers.h"

#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"
#include "Common/GeometryGenerator.h"
#include "Common/Camera.h"
#include "DirectXMath.h"
#include "Category.h"
#include <vector>
#include <memory>
#include "FrameResource.h"
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
	explicit StateStack(State::Context context);

	template <typename T>
	void registerState(States::ID stateID);

	void update(const GameTimer& gt);
	void draw();
	void buildScene();
	void handleEvent(const Event& event);

	void pushState(States::ID stateID);
	void popState();
	void clearStates();

	bool isEmpty() const;

private:
	State::Ptr createState(States::ID stateID);
	void applyPendingChanges();

private:
	struct PendingChange
	{
		explicit PendingChange(Action action, States::ID stateID = States::ID::None);

		Action action;
		States::ID stateID;
	};

private:
	std::vector<State::Ptr> mStack;
	std::vector<PendingChange> mPendingList;

	State::Context mContext;
	std::map<States::ID, std::function<State::Ptr()>> mFactories;
};

template <typename T>
void StateStack::registerState(States::ID stateID)
{
	mFactories[stateID] = [this]()
	{
		return State::Ptr(new T(*this, mContext));
	};
}

#endif // BOOK_STATESTACK_H