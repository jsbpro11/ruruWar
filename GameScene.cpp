#include "DXUT.h"
#include "Header.h"

CGameScene::CGameScene()
	: BG(new CMatrix())
{

}

CGameScene::~CGameScene()
{

}

void CGameScene::Update(float deltaTime)
{
	BG->Update(deltaTime);
}

void CGameScene::Render(LPD3DXSPRITE sprite)
{
	BG->Draw(sprite, gAssetManager->gameBGTexture);
}

void CGameScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{

}