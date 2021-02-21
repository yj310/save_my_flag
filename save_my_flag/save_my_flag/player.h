#pragma once
#include "global.h"

class Player
{
public:
	Player();

	void Update();
	void Render();

	void Jump();
	void Gravity();

	void setPos(float x, float y);
	D3DXVECTOR2 getPos();
	int getRadious();
	float getSpeed();
	bool getIsDead();
	void IsDead() { isDead = true; }
	D3DXVECTOR2 getSize();
	D3DXVECTOR2 getCenter();
	void setPrintPos();
	D3DXVECTOR2 getPrintPos() { return { printX, printY }; }

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
	int radious;
	float jumpStartPosY;
	bool isDead;
	//
	int randCharacter;
	float printX;
	float printY;


	bool isTouch_top;
	bool isTouch_bottom;
	bool isTouch_right;
	bool isTouch_left;

};