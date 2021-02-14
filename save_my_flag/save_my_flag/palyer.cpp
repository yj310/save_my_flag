#include "player.h"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100

Player::Player()
{
	posX = 0;
	posY = 0;
	radious = 100;
	isDead = false;
	width = PLAYER_WIDTH;
	height = PLAYER_HEIGHT;
}

void Player::Update()
{

}

void Player::Render()
{
	TextureElement* element = textureManager.getTexture(TEX_PLAYER);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	cen = { width / 2, height / 2, 0 };
	pos = { 500, 500, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

D3DXVECTOR2 Player::getPos()
{
	return { posX, posY };
}

int  Player::getRadious()
{
	return radious;
}

bool Player::getIsDead()
{
	return isDead;
}