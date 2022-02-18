#pragma once
#include "SceneNode.h"
#include "Aircraft.h"
#include "SpriteNode.h"
#include "RenderLayer.h"

//! World class. Initialize our world in here.
class World
{
public:
	//! World constructor takes in a game class to initialize our world.
	explicit World(Game* window);

	//! Updates world.
	void update(const GameTimer& gt);

	//! Draws world.
	void draw();

	//! Load textures of world.
	void loadTextures(Microsoft::WRL::ComPtr<ID3D12Device>& GameDevice,
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>& CommandList,
		std::unordered_map<std::string, std::unique_ptr<Texture>>& GameTextures);

	//! Builds materials of world.
	void buildMaterials(std::unordered_map<std::string, std::unique_ptr<Material>>& GameMaterials);

	//! Builds some shape geometry for our game world. (Some un-needed).
	void buildShapeGeometry(Microsoft::WRL::ComPtr<ID3D12Device>& GameDevice,
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>& CommandList,
		std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>& GameGeometries);

	//! Builds scene.
	void buildScene();

private:
	//! Reference to game class.
	Game* mGame;

	//! Reference to parent scene node.
	SceneNode* mSceneGraph;

	//! Scene layers.
	std::array<SceneNode*, RenderLayer::Count> mSceneLayers;

	//! World bounds.
	XMFLOAT4 mWorldBounds;

	//! Spawn position.
	XMFLOAT2 mSpawnPosition;

	//! Scroll speed of world.
	float mScrollSpeed;

	//! Player aircraft.
	Aircraft* mPlayerAirCraft;

	//! Side aircraft.
	Aircraft* mEnemyAircraft;

	//! Side aircraft.
	Aircraft* mEnemyAircraft2;

	//! Scrolling background.
	SpriteNode* mBackground;
	SpriteNode* mBackground2;

};
