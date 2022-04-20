#include "MenuState.h"
#include "SpriteNode.h"
#include "Game.h"

MenuState::MenuState(StateStack* stack, Context* context) : State(stack, context)
{
    mAllRitems.clear();
    mContext->game->ResetFrameResources();
    mContext->game->BuildMaterials();

    std::unique_ptr<SpriteNode> backgroundSprite = std::make_unique<SpriteNode>(this);
    backgroundSprite->SetMatGeoDrawName("Menu", "shapeGeo", "box");
    backgroundSprite->setScale(11.5, 1.0, 9.0);
    backgroundSprite->setPosition(0, 0, 0);
    mSceneGraph->attachChild(std::move(backgroundSprite));

    mSceneGraph->build();
    mContext->game->BuildFrameResources(mAllRitems.size());
}

MenuState::~MenuState()
{
}

void MenuState::draw()
{
    mSceneGraph->draw();
}

bool MenuState::update(const GameTimer& gt)
{
    mSceneGraph->update(gt);

    return true;
}

bool MenuState::handleEvent(WPARAM btnState)
{
    if (d3dUtil::IsKeyDown('P'))
    {
        requestStackPop();
        requestStackPush(States::Game);
    }
    else if (d3dUtil::IsKeyDown('Q'))
    {
        PostQuitMessage(0);
    }

    return true;
}

bool MenuState::handleRealtimeInput()
{
    return true;
}
