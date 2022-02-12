#pragma once
#include <iostream>
#include "Common/d3dApp.h"
#include "DirectXMath.h"
#include "Game.h"
#include <vector>
#include <memory>

using namespace DirectX;
using namespace DirectX::PackedVector;

class SceneNode
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode(Game* game);

	void attachChild(Ptr child);
	Ptr detachChild(const SceneNode& node);

	XMFLOAT3 getWorldPosition() const;
	void setWorldPosition(float x, float y, float z);

	XMFLOAT3 getWorldRotation() const;
	void setWorldRotation(float x, float y, float z);

	XMFLOAT3 getWorldScale() const;
	void setWorldScale(float x, float y, float z);

	XMFLOAT4X4 getWorldTransform() const;
	XMFLOAT4X4 getTransform() const;

	void Update(const GameTimer& dt);
	void move(float x, float y, float z);
	void draw() const;
	void build();

private:
	virtual void updateCurrent(GameTimer dt);
	void updateChildren(GameTimer dt);
	virtual void drawCurrent() const;
	void drawChildren() const;
	virtual void buildCurrent();
	void buildChildren();

protected:

	Game* game;

	RenderItem* renderer;

private:

	std::vector<Ptr> mChildren;

	SceneNode* mParent;

	XMFLOAT3 mWorldPosition;
	XMFLOAT3 mWorldRotation;
	XMFLOAT3 mWorldScaling;
};