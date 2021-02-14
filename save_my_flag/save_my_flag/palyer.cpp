#include "player.h"

Player::Player()
{
	posX = 0;
	posY = 0;
	radious = 100;
	isDead = false;
}

void Player::Update()
{

}

void Player::Render()
{

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