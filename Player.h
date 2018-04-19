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
	RECT enemyRect; //�ӽ� �浹, GameScene�� ���ʹ̸���Ʈ ���� ���ʹ� �浹 �������� ���� CGameScene Ŭ������ �޾ƿ���
	RECT enemyAttackRect; //�ӽ� �浹, GameScene�� ���ʹ̸���Ʈ ���� ���ʹ� �浹 �������� ���� CGameScene Ŭ������ �޾ƿ���

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