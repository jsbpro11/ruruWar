#pragma once

class CPlayer : public CMatrix
{
private:
	enum EPlayerState
	{
		IDLE, MOVE, ATTACK, HIT, DIE
	};
	EPlayerState state;

public:
	int type;
	D3DXVECTOR2 pos;
	RECT ref;
	RECT hitRect;
	RECT aimRect;
	RECT attackRect;
	RECT enemyRect; //임시 충돌, GameScene에 에너미리스트 들어가면 에너미 충돌 영역으로 ㄱㄱ CGameScene 클래스도 받아오기
	RECT enemyAttackRect; //임시 충돌, GameScene에 에너미리스트 들어가면 에너미 충돌 영역으로 ㄱㄱ CGameScene 클래스도 받아오기

	int hp;
	int speed;
	int damage;

	float attackTime;
	float attackTimer;

	bool isDie;

public:
	CPlayer(D3DXVECTOR2 position, int type);
	~CPlayer();
	virtual void Update(float deltaTime);
	virtual void Render(LPD3DXSPRITE sprite);
	
	void ChangeState(EPlayerState state);
};