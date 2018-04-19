#include "DXUT.h"
#include "Header.h"

CTitleScene::CTitleScene()
	:CScene(), titleImage(new CMatrix), mouseX(0), mouseY(0), leftMouseClicked(false), isOption(false)
{

}

CTitleScene::~CTitleScene()
{
	delete titleImage;
}

void CTitleScene::Update(float deltaTime)
{
	CScene::Update(deltaTime);
	RECT ref;

	titleImage->Update(deltaTime);

	SetRect(&mouseRect, mouseX - 1, mouseY - 1, mouseX + 1, mouseY + 1);
	SetRect(&startRect, 260, 400, 800, 500);
	SetRect(&optionRect, 290, 550, 730, 650);

	if (leftMouseClicked)
	{
		leftMouseClicked = false;

		if (IntersectRect(&ref, &mouseRect, &startRect))
			ChangeScene(1);

		if (IntersectRect(&ref, &mouseRect, &optionRect))
			isOption = !isOption;
	}
}

void CTitleScene::Render(LPD3DXSPRITE sprite)
{
	CScene::Render(sprite);

	titleImage->Draw(sprite, gAssetManager->titleTexture);
}

void CTitleScene::MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_MOUSEMOVE:
		mouseX = LOWORD(lParam);
		mouseY = HIWORD(lParam);
		break;
	case WM_LBUTTONDOWN:
		leftMouseClicked = true;
		break;
	}
}