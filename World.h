#pragma once
#include "SceneNode.h"
#include "Aircraft.h"
#include "SpriteNode.h"
#include "RenderLayer.h"

class World //World class. Initialize our world in here.
{
public:
	explicit World(Game* window); //World constructor takes in a game class to initialize our world.

	void update(const GameTimer& gt); //Updates world.

	void draw(); //Draws world.

	void loadTextures(Microsoft::WRL::ComPtr<ID3D12Device>& GameDevice,
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>& CommandList,
		std::unordered_map<std::string, std::unique_ptr<Texture>>& GameTextures); //Load textures of world.
	void buildMaterials(std::unordered_map<std::string, std::unique_ptr<Material>>& GameMaterials); //Builds materials of world.
	void buildShapeGeometry(Microsoft::WRL::ComPtr<ID3D12Device>& GameDevice,
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>& CommandList,
		std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>& GameGeometries); //Builds some shape geometry for our game world. (Some un-needed).

	void buildScene(); //Builds scene.


private:

	enum Layer // Enum in which layers are renderered.
	{
		Background,
		Air,
		LayerCount,
	};

private:
	Game* mGame; //Reference to game class.

	SceneNode* mSceneGraph; //Reference to parent scene node.

	std::array<SceneNode*, RenderLayer::Count> mSceneLayers; //Scene layers.

	XMFLOAT4 mWorldBounds; //World bounds.

	XMFLOAT2 mSpawnPosition; //Spawn position.

	float mScrollSpeed; //Scroll speed of world.

	Aircraft* mPlayerAirCraft; //Player aircraft.
	Aircraft* mEnemyAircraft; //Side aircraft.
	Aircraft* mEnemyAircraft2; //Side aircraft.


	SpriteNode* mBackground; //Scrolling background.
	SpriteNode* mBackground2;

};
