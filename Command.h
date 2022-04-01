#pragma once
#include <functional>
#include "Common/d3dApp.h"
#include <cassert>
#include "Category.h"

class SceneNode;

struct Command
{
	Command();

	std::function<void(SceneNode&, GameTimer)> action;
	unsigned int category;
};

template <typename GameObject, typename Function>
std::function<void(SceneNode&, GameTimer)> derivedAction(Function fn)
{
	return [=](SceneNode& node, GameTimer dt)
	{
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		fn(static_cast<GameObject&>(node), dt);
	};

}