#ifndef BOOK_STATE_H
#define BOOK_STATE_H

#pragma once
#include "StateIdentifiers.h"
#include <memory>
#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"
#include "Common/GeometryGenerator.h"
#include "Common/Camera.h"
#include "RenderLayer.h"
#include "SceneNode.h"
#include "DirectXMath.h"
#include "Category.h"
#include <vector>
#include <memory>
#include "FrameResource.h"
#include <utility>
#include <functional>
#include <map>


class Player;
class Game;
class StateStack;
class Event;

class State
{
public:
	typedef std::unique_ptr<State> Ptr;

	struct Context
	{
		Context(Game* window, Player* player);

		Game* window;
		Player* player;
	};

public:
	State(StateStack& stack, Context context);
	virtual ~State();

	virtual void draw() = 0;
	virtual void buildScene() = 0;
	virtual bool update(const GameTimer& gt) = 0;
	virtual bool		handleEvent(const Event& event) = 0;

	std::vector<RenderItem*> getRenderItems();

	void AddRenderItem(RenderItem* renderItem);
	virtual void OnKeyDown(WPARAM btnState) = 0;
	Context getContext() const;
protected:
	void requestStackPush(States::ID stateID);
	void requestStackPop();
	void requestStateClear();
	std::vector<RenderItem*> mAllRitems;
	StateStack* mStack;
	Context mContext;
};

#endif // BOOK_STATE_HPP