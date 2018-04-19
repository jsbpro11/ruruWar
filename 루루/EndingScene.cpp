#include "DXUT.h"
#include "Header.h"

CEndingScene::CEndingScene(bool isWin)
	:CScene(), victoryImage(new CMatrix), loseImage(new CMatrix), isWin(false)
{
	this->isWin = isWin;
}

CEndingScene::~CEndingScene()
{
	delete victoryImage;
	delete loseImage;
}

void CEndingScene::Update(float deltaTime)
{
	CScene::Update(deltaTime);

	if (isWin)
		victoryImage->Update(deltaTime);
	else
		loseImage->Update(deltaTime);
}

void CEndingScene::Render(LPD3DXSPRITE sprite)
{
	CScene::Render(sprite);

	if (isWin)
		victoryImage->Draw(sprite, gAssetManager->victoryTexture);
	else
		loseImage->Draw(sprite, gAssetManager->loseTexture);
}

void  CEndingScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_KEYDOWN:
		switch (wParam)
		{
		case VK_RETURN:
			CEndingScene::~CEndingScene();
			ChangeScene(0);
		}
	}
}