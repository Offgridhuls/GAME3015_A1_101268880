#pragma once
#include <functional>
#include "Common/d3dApp.h"
#include <cassert>
#include "Category.h"

class SceneNode;

//! Command struct, has an action and a category.
struct Command
{
	Command();

	std::function<void(SceneNode&, GameTimer)> action;
	unsigned int category;
};

//! Checks if there's a node and a derived action
template <typename GameObject, typename Function>
std::function<void(SceneNode&, GameTimer)> derivedAction(Function fn)
{
	return [=](SceneNode& node, GameTimer dt)
	{
		assert(dynamic_cast<GameObject*>(&node) != nullptr);

		fn(static_cast<GameObject&>(node), dt);
	};

}