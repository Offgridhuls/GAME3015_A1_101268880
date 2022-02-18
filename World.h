#pragma once
#include "SceneNode.h"
#include "Aircraft.h"
#include "SpriteNode.h"

class World
{
public:
	explicit World(Game* window);

	void update(const GameTimer& gt);

	void draw();

	void loadTextures(Microsoft::WRL::ComPtr<ID3D12Device>& GameDevice,
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>& CommandList,
		std::unordered_map<std::string, std::unique_ptr<Texture>>& GameTextures);
	void buildMaterials(std::unordered_map<std::string, std::unique_ptr<Material>>& GameMaterials);
	void buildShapeGeometry(Microsoft::WRL::ComPtr<ID3D12Device>& GameDevice,
		Microsoft::WRL::ComPtr<ID3D12GraphicsCommandList>& CommandList,
		std::unordered_map<std::string, std::unique_ptr<MeshGeometry>>& GameGeometries);

	void buildScene();


private:

	enum Layer
	{
		Background,
		Air,
		LayerCount,
	};

private:
	Game* mGame;

	SceneNode* mSceneGraph;

	std::array<SceneNode*, LayerCount> mSceneLayers;

	XMFLOAT4 mWorldBounds;

	XMFLOAT2 mSpawnPosition;

	float mScrollSpeed;

	Aircraft* mPlayerAirCraft;

	SpriteNode* mBackground;

};
