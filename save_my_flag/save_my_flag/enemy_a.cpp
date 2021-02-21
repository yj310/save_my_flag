#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(float x, float y, float direction)
{
	posX = x;
	posY = y;
	state = TEX_ENEMY_A_1;
	state_count = 20;
	radious = 50;
	width = 100;
	height = 100;
	speed = 3;
	gravity = GRAVITY;
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

	cen = { width / 2, height / 2, 0 };
	pos = { gameSystem.getPrintPos(posX, posY).x, gameSystem.getPrintPos(posX, posY).y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void EnemyA::Update()
{
	Gravity();
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

