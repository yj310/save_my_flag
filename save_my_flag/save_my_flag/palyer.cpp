#include "player.h"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100
#define PLAYER_BOTTOM 860

Player::Player()
{
	posX = 110;
	posY = PLAYER_BOTTOM;
	jumpStartPosY = posY;
	radious = 100;
	isJump = false;
	isDead = false;
	speed = 5;
	jumpHeight = 0;
	jumpTime = 0.0f;
	jumpPower = 40.0f;
	
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

void Player::Update()
{
	if (inputManager.keyBuffer[VK_LEFT] == 1)
	{
		posX -= speed;
	}
	else if (inputManager.keyBuffer[VK_RIGHT] == 1)
	{
		posX += speed;
	}

	if (inputManager.keyBuffer[VK_UP] == 1 && !isJump)
	{
		jumpStartPosY = posY;
		isJump = true;
	}

	if (isJump)
	{
		Jump();
	}
	posY = jumpStartPosY + jumpHeight;
}



void Player::Jump()
{
	jumpHeight = jumpTime * jumpTime - jumpPower * jumpTime;

	jumpTime += 1.0f;

	if (jumpTime >= jumpPower)
	{
		jumpTime = 0.f;
		jumpHeight = 0.f;

		isJump = false;
	}
}

float Player::getSpeed()
{
	return speed;
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