#include "DXUT.h"
#include "Header.h"

AssetManager* gAssetManager;

void AssetManager::LoadAssets()
{
	mobTexture = new CTexture(L"images/Object/Mob00", L"png", 1);

	gameBGTexture = new CTexture(L"images/Map/Map00", L"png", 1);

	howToTexture = new CTexture(L"images/Main/TitleScene/HowTo00", L"png", 1);
	rankingTexture = new CTexture(L"images/Main/TitleScene/Ranking00", L"png", 1);
	titleTexture = new CTexture(L"images/Main/TitleScene/Title00", L"png", 1);

	victoryTexture = new CTexture(L"images/Main/EndingScene/Victory00", L"png", 1);
	loseTexture = new CTexture(L"images/Main/EndingScene/Lose00", L"png", 1);
}

void AssetManager::ReleaseAssets()
{
	delete mobTexture;

	delete gameBGTexture;

	delete titleBGTexture;

	delete howToTexture;
	delete rankingTexture;
	delete titleTexture;

	delete victoryTexture;
	delete loseTexture;
}