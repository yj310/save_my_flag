#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(float x, float y, float direction)
{
	posX = x;
	posY = y;
	state = TEX_ENEMY_A_1;
	state_count = 20;
	width = 100;
	height = 100;
	speed = 3;
	this->direction = direction;
}

void EnemyA::Render()
{
	TextureElement* element = textureManager.getTexture(state);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	cen = { width / 2, height, 0 };
	pos = { posX, posY, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void EnemyA::Update()
{
	posX += direction * speed;



	state_count += 1;
	if (state_count >= 20)
	{
		state_count = 0;
		if (direction < 0)
		{
			if (state != TEX_ENEMY_A_1)
			{
				state = TEX_ENEMY_A_1;
			}
			else if (state != TEX_ENEMY_A_2)
			{
				state = TEX_ENEMY_A_2;
			}
		}
		else
		{
			if (state != TEX_ENEMY_A_3)
			{
				state = TEX_ENEMY_A_3;
			}
			else if (state != TEX_ENEMY_A_4)
			{
				state = TEX_ENEMY_A_4;
			}
		}

	}
}




D3DXVECTOR2 EnemyA::getPos()
{
	return { posX, posY };
}

void EnemyA::setPos(float x, float y)
{
	posX = x;
	posY = y;
}

D3DXVECTOR2 EnemyA::getSize()
{
	return { width, height };
}

void EnemyA::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

int EnemyA::getState()
{
	return state;
}

void EnemyA::setState(int state)
{
	this->state = state;
}

float EnemyA::getDirection()
{
	return direction;
}

void EnemyA::setDirection(float direction)
{
	this->direction = direction;
}

float EnemyA::getSpeed()
{
	return speed;
}

void EnemyA::setSpeed(float speed)
{
	this->speed = speed;
}

