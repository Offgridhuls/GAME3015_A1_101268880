#pragma once
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

using Microsoft::WRL::ComPtr;
using namespace DirectX;
using namespace DirectX::PackedVector;

#pragma comment(lib, "d3dcompiler.lib")
#pragma comment(lib, "D3D12.lib")

struct RenderItem
{
	RenderItem() = default;
	RenderItem(const RenderItem& rhs) = delete;

	// World matrix of the shape that describes the object's local space
	// relative to the world space, which defines the position, orientation,
	// and scale of the object in the world.
	XMFLOAT4X4 World = MathHelper::Identity4x4();

	XMFLOAT4X4 TexTransform = MathHelper::Identity4x4();

	// Dirty flag indicating the object data has changed and we need to update the constant buffer.
	// Because we have an object cbuffer for each FrameResource, we have to apply the
	// update to each FrameResource.  Thus, when we modify obect data we should set 
	// NumFramesDirty = gNumFrameResources so that each frame resource gets the update.
	int NumFramesDirty = gNumFrameResources;

	// Index into GPU constant buffer corresponding to the ObjectCB for this render item.
	UINT ObjCBIndex = -1;

	Material* Mat = nullptr;
	MeshGeometry* Geo = nullptr;

	// Primitive topology.
	D3D12_PRIMITIVE_TOPOLOGY PrimitiveType = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST;

	// DrawIndexedInstanced parameters.
	UINT IndexCount = 0;
	UINT StartIndexLocation = 0;
	int BaseVertexLocation = 0;
};

class Game;
struct Command;
class State;

//! Scene node class, initialize a Scenenode using this class.
class SceneNode 
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode(State* game); //Scenenode Constructor

	void onCommand(const Command& command, GameTimer dt);
	virtual unsigned int getCategory() const;

	 //! Attaches specified child to parent object
	void attachChild(Ptr child);

	//! Detaches specified child from parent object.
	Ptr detachChild(const SceneNode& node);

	// !Get world position returns mWorldPosition.
	XMFLOAT3 getWorldPosition() const;

	//! Sets world position.
	void setWorldPosition(float x, float y, float z);

	//! Get world rotation.
	XMFLOAT3 getWorldRotation() const;

	//! Set world rotation.
	void setWorldRotation(float x, float y, float z);

	//! Get world scale.
	XMFLOAT3 getWorldScale() const;

	//! Set world scale.
	void setWorldScale(float x, float y, float z); 

	//! Gets world orientation. 
	XMFLOAT4X4 getWorldTransform() const;

	//! Gets transform of object.
	XMFLOAT4X4 getTransform() const;

	//! Update function of Scenenode.
	void Update(const GameTimer& dt);

	//! Move function of Scenenode-moves object by velocity.
	void move(float x, float y, float z);
	void draw() const; 
	void build();

private:
	virtual void updateCurrent(GameTimer dt); 

	//! Updates children.
	void updateChildren(const GameTimer dt);

	//! Does nothing.
	virtual void drawCurrent() const;

	//! Draws children
	void drawChildren() const;

	//! Does nothing.
	virtual void buildCurrent();

	//! Builds Children.
	void buildChildren();

protected:
	//! Reference to game class.
	State* mState;

	//! Reference to renderer.
	RenderItem* renderer;

private:
	//! Children vector
	std::vector<Ptr> mChildren;

	//! Parent node.
	SceneNode* mParent;

	//! World position.
	XMFLOAT3 mWorldPosition;

	//! World rotation.
	XMFLOAT3 mWorldRotation;

	//! World scaling.
	XMFLOAT3 mWorldScaling;
};