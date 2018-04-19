#include "DXUT.h"
#include "Header.h"

CPlayer::CPlayer(D3DXVECTOR2 position, int type)
	: state(MOVE)
{
	pos = position;
	this->type = type;

	switch (type)
	{
	case 1:
		// �⺻ �����
		hp = 10;
		speed = 10;
		damage = 10;
		attackTime = 1.5f;
		break;
	case 2:
		// �� �����
		hp = 10;
		speed = 10;
		damage = 10;
		attackTime = 1.5f;
		break;
	case 3:
		// ��Ʋ��
		hp = 10;
		speed = 10;
		damage = 10;
		attackTime = 1.5f;
		break;
	case 4:
		//¡�� �����
		hp = 10;
		speed = 10;
		damage = 10;
		attackTime = 1.5f;
		break;
	case 5:
		//Ȳ�� �����
		hp = 10;
		speed = 10;
		damage = 10;
		attackTime = 1.5f;
		break;
	}
}

CPlayer::~CPlayer()
{

}

void CPlayer::Update(float deltaTime)
{
	CMatrix::Update(deltaTime);

	if (IntersectRect(&ref, &hitRect, &enemyAttackRect))
	{
		ChangeState(HIT);
	}

	if (state == MOVE)
	{
		if (IntersectRect(&ref, &aimRect, &enemyRect))
		{
			ChangeState(IDLE);
		}
	}

	if (state == IDLE)
	{
		attackTimer += deltaTime;
		if (attackTimer >= attackTime)
		{
			attackTimer = 0;
			ChangeState(ATTACK);
			
		}
	}

	if (state == ATTACK)
	{


		if (isAniEnd)
		{
			state = IDLE;
		}
	}
}

void CPlayer::Render(LPD3DXSPRITE sprite)
{
	switch (type)
	{
	case 1:
		switch (state)
		{
		case IDLE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case MOVE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case ATTACK:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case HIT:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case DIE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		}
		break;
	case 2:
		switch (state)
		{
		case IDLE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case MOVE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case ATTACK:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case HIT:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case DIE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		}
		break;
	case 3:
		switch (state)
		{
		case IDLE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case MOVE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case ATTACK:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case HIT:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case DIE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		}
		break;
	case 4:
		switch (state)
		{
		case IDLE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case MOVE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case ATTACK:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case HIT:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case DIE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		}
		break;
	case 5:
		switch (state)
		{
		case IDLE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case MOVE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case ATTACK:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case HIT:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		case DIE:
			Draw(sprite, gAssetManager->mobTexture);
			break;
		}
		break;
	}
}

void CPlayer::ChangeState(EPlayerState state)
{
	this->state = state;

	switch (type)
	{
	case 1: // �⺻ �����
		switch (state)
		{
		case IDLE:
			SetAnimation(0.03f, 1, true);
			break;
		case MOVE:
			SetAnimation(0.03f, 1, true);
			break;
		case ATTACK:
			SetAnimation(0.03f, 1, false);
			break;
		case HIT:
			SetAnimation(0.03f, 1, false);
			break;
		case DIE:
			SetAnimation(0.03f, 1, false);
			break;
		}
		break;
	case 2: // ����� ��
		switch (state)
		{
		case IDLE:
			SetAnimation(0.03f, 1, true);
			break;
		case MOVE:
			SetAnimation(0.03f, 1, true);
			break;
		case ATTACK:
			SetAnimation(0.03f, 1, false);
			break;
		case HIT:
			SetAnimation(0.03f, 1, false);
			break;
		case DIE:
			SetAnimation(0.03f, 1, false);
			break;
		}
		break;
	case 3: // ��Ʋ��
		switch (state)
		{
		case IDLE:
			SetAnimation(0.03f, 1, true);
			break;
		case MOVE:
			SetAnimation(0.03f, 1, true);
			break;
		case ATTACK:
			SetAnimation(0.03f, 1, false);
			break;
		case HIT:
			SetAnimation(0.03f, 1, false);
			break;
		case DIE:
			SetAnimation(0.03f, 1, false);
			break;
		}
		break;
	case 4: // ¡�� �����
		switch (state)
		{
		case IDLE:
			SetAnimation(0.03f, 1, true);
			break;
		case MOVE:
			SetAnimation(0.03f, 1, true);
			break;
		case ATTACK:
			SetAnimation(0.03f, 1, false);
			break;
		case HIT:
			SetAnimation(0.03f, 1, false);
			break;
		case DIE:
			SetAnimation(0.03f, 1, false);
			break;
		}
		break;
	case 5: // Ȳ�� �����
		switch (state)
		{
		case IDLE:
			SetAnimation(0.03f, 1, true);
			break;
		case MOVE:
			SetAnimation(0.03f, 1, true);
			break;
		case ATTACK:
			SetAnimation(0.03f, 1, false);
			break;
		case HIT:
			SetAnimation(0.03f, 1, false);
			break;
		case DIE:
			SetAnimation(0.03f, 1, false);
			break;
		}
		break;
	}
}