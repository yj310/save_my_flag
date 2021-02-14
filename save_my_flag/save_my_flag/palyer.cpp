#include "player.h"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100

Player::Player()
{
	posX = 500;
	posY = 500;
	radious = 100;
	isDead = false;

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
	rc.right = PLAYER_WIDTH;
	rc.bottom = PLAYER_HEIGHT;

	cen = { PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2, 0 };
	pos = { posX, posY, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

D3DXVECTOR2 Player::getPos()
{
	return { posX, posY };
}

D3DXVECTOR2 Player::getSize()
{
	return { PLAYER_WIDTH, PLAYER_HEIGHT };
}

int  Player::getRadious()
{
	return radious;
}

bool Player::getIsDead()
{
	return isDead;
}