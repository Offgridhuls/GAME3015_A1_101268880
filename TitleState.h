#pragma once
#include "State.h"
#include "SpriteNode.h"
#include "Event.h"

class Game;

class TitleState : public State
{
public:
	TitleState(StateStack& stack, Context context);

	virtual void draw();
	virtual void buildScene();
	virtual bool update(const GameTimer& gt);
	virtual bool handleEvent(const Event& event);
	virtual void ProcessInput();
	virtual void OnKeyDown(WPARAM btnState);

private:
	SpriteNode* mBackground;
	SceneNode* mSceneGraph;

	bool mShowText;
};