#pragma once
#include "global.h"

class Player
{
public:
	Player();

	void Update();
	void Render();

	void Jump();
	void Down();

	void setPos(float x, float y);
	D3DXVECTOR2 getPos();
	int getRadious();
	float getSpeed();
	bool getIsDead();
	D3DXVECTOR2 getSize();
	D3DXVECTOR2 getCenter();

	float accumulatedGravityPower;
	float jumpHeight;
	float jumpTime;
	float jumpPower;
	float gravity;
	float speed;
	bool isJump;
	bool isHit;
	float posX;
	float posY;
	float jumpStartPosY;
	int radious;
	bool isDead;
	bool isDown;
	//
	int state;

};