#pragma once

class CTitleScene : public CScene
{
public:
	CMatrix* titleImage;

	int mouseX;
	int mouseY;
	
	bool leftMouseClicked;
	bool isOption;

	RECT mouseRect;
	RECT startRect;
	RECT optionRect;

public:
	CTitleScene();
	virtual ~CTitleScene();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprtie);
	virtual void MsgProc(UINT uMsg, WPARAM wParam, LPARAM lParam);
};