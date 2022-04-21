#pragma once
#include "StateIdentifiers.h"
#include "Common/d3dApp.h"
#include "FrameResource.h"
#include "SceneNode.h"


#include <memory>

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;


class StateStack;
class Player;
class Game;
class SceneNode;

class State
{
public:
	typedef std::unique_ptr<State> StatePtr;
	struct Context
	{
		Context(Game* _game, Player* _player);
		Game* game;
		Player* player;
	};
public:
	//!State constructor takes in a stack and a context.
	State(StateStack* stack, Context* context);
	virtual ~State();
	//!Draw function of each state.
	virtual void draw() = 0;
	//!Update function of each state.
	virtual bool update(const GameTimer& gt) = 0;
	//!Handles btn clicks for a state.
	virtual bool handleEvent(WPARAM btnState) = 0;
	virtual bool handleRealtimeInput() = 0;


	XMFLOAT3 getCameraPos() { return mCameraPos; }
	XMFLOAT3 getTargetPos() { return mTargetPos; }

	std::vector<std::unique_ptr<RenderItem>>& getRenderItems() { return mAllRitems; }
	Context* getContext() const;

protected:
	//!Pushes a state into the stateStack.
	void requestStackPush(States::ID stateID);
	//!Removes a state from the stack.
	void requestStackPop();
	void requestStateClear();

protected:
	StateStack* mStack;
	Context* mContext;

	XMFLOAT3 mCameraPos;
	XMFLOAT3 mTargetPos;

	std::unique_ptr<SceneNode> mSceneGraph;

	std::vector<std::unique_ptr<RenderItem>> mAllRitems;
};

