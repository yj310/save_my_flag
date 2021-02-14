#pragma once
#include "global.h"

class Player
{
public:
	Player();

	void Update();
	void Render();

	void Jump();
	void setPos(float x, float y);
	D3DXVECTOR2 getPos();
	int getRadious();
	float getSpeed();
	bool getIsDead();
	D3DXVECTOR2 getSize();

	float jumpHeight;
	float jumpTime;
	float jumpPower;
	float speed;
	bool isJump;
	bool isHit;
	float posX;
	float posY;
	float jumpStartPosY;
	int radious;
	bool isDead;

};