#include "player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
	radious = 100;
	isDead = false;
	//width = 
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
	rc.right = 100;
	rc.bottom = ;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

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