#include "enemy_a.h"
#include "global.h"

EnemyA::EnemyA(float x, float y)
{
	posX = x;
	posY = y;
	enemy_state = TEX_ENEMY_A;
	enemy_width = 100;
	enemy_height = 100;
}

void EnemyA::Render()
{
	TextureElement* element = textureManager.getTexture(enemy_state);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = enemy_width;
	rc.bottom = enemy_height;

	cen = { enemy_width / 2, enemy_height / 2, 0 };
	pos = { posX, posY, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void EnemyA::Update()
{

}

D3DXVECTOR2 EnemyA::getPos()
{
	return { posX, posY };
}

D3DXVECTOR2 EnemyA::getSize()
{
	return { enemy_width, enemy_height };
}

int EnemyA::getState()
{

}