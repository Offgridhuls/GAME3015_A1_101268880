#pragma once
#include "Common/d3dApp.h"
#include "Common/MathHelper.h"
#include "Common/UploadBuffer.h"
#include "Common/GeometryGenerator.h"
#include "Common/Camera.h"
#include "DirectXMath.h"
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

class SceneNode //Scene node class, initialize a Scenenode using this class.
{
public:
	typedef std::unique_ptr<SceneNode> Ptr;

public:
	SceneNode(Game* game); //Scenenode Constructor

	void attachChild(Ptr child); //Attaches specified child to parent object.
	Ptr detachChild(const SceneNode& node);  //Detaches specified child from parent object.

	XMFLOAT3 getWorldPosition() const; //Get world position returns mWorldPosition.
	void setWorldPosition(float x, float y, float z); //Sets world position.

	XMFLOAT3 getWorldRotation() const; // Get world rotation.
	void setWorldRotation(float x, float y, float z); //Set world rotation.

	XMFLOAT3 getWorldScale() const; //Get world scale.
	void setWorldScale(float x, float y, float z); //Set world scale.

	XMFLOAT4X4 getWorldTransform() const; //Gets world orientation. 
	XMFLOAT4X4 getTransform() const; //Gets transform of object.

	void Update(const GameTimer& dt); //Update function of Scenenode.
	void move(float x, float y, float z); //Move function of Scenenode-moves object by velocity.
	void draw() const; 
	void build();

private:
	virtual void updateCurrent(GameTimer dt); 
	void updateChildren(const GameTimer dt); //Updates children.
	virtual void drawCurrent() const; //Does nothing.
	void drawChildren() const; //Draws children
	virtual void buildCurrent(); //Does nothing.
	void buildChildren(); //Builds Children.

protected:

	Game* game; //Reference to game class.

	RenderItem* renderer; //Reference to renderer.

private:

	std::vector<Ptr> mChildren; //Children vector

	SceneNode* mParent; //Parent node.

	XMFLOAT3 mWorldPosition; //World position.
	XMFLOAT3 mWorldRotation; //World rotation.
	XMFLOAT3 mWorldScaling; //World scaling.
};