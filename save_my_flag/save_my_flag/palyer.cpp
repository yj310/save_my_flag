﻿#include "player.h"
#include "global.h"

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100
#define PLAYER_BOTTOM 860

Player::Player()
{
	posX = 250;
	jumpStartPosY = PLAYER_BOTTOM;
	posY = jumpStartPosY;
	radious = 50;
	isJump = false;
	isDead = false;
	speed = 15;
	isDown = false;
	//gravity = 150.5;	//중력가속도
	jumpTime = 0.0f;	//점프 이후 경과시간
	jumpPower = 40.0f;	//점프력
	jumpHeight = 0;
	//
	state = 255;

}

void Player::Update()
{
	posY += 20;
	//accumulatedGravityPower = deltaTime * gravity;
	//posY += accumulatedGravityPower;

	//player 
	if (inputManager.keyBuffer['A'] == 1)
	{
		posX -= speed;
	}
	else if (inputManager.keyBuffer['D'] == 1)
	{
		posX += speed;
	}
	else if (inputManager.keyBuffer['S'] == 1)
	{
		posY += speed;
	}
	if (inputManager.keyBuffer['W'] == 1 && !isJump)
	{
		isJump = true;
		jumpStartPosY = jumpStartPosY;
	}

	//jump
	if (isJump)
	{
		Jump();
		posY = jumpStartPosY + jumpHeight;
	}
	/*else
	{
		if (isDown)
		{
			Down();
		}
	}*/



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

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, state, 255, 255));

	element->sprite->End();
}

void Player::Down()
{
	posY += 15;
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

D3DXVECTOR2 Player::getCenter()
{
	return { PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2 };
}

float Player::getSpeed()
{
	return speed;
}

void Player::setPos(float x, float y)
{
	posX = x;
	posY = y;

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