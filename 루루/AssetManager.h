#pragma once

class AssetManager
{
public:

	CTexture*	titleBGTexture;

	CTexture*	howToTexture;
	CTexture*	rankingTexture;
	CTexture*	titleTexture;

	CTexture*	victoryTexture;
	CTexture*	loseTexture;

	void LoadAssets();
	void ReleaseAssets();
};

extern AssetManager* gAssetManager;