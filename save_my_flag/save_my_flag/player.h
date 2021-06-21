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
	int getCoin() { return coin_c; }
	int setCoin(int c) { coin_c = c; }
	void AddCoin() { coin_c += 1; }

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
	float bottomY;
	int radious;
	float jumpStartPosY;
	bool isDead;
	bool isClear;
	//
	int randCharacter;
	float printX;
	float printY;

	int score;
	int coin_c;


	bool isTouch_top;
	bool isTouch_bottom;
	bool isTouch_right;
	bool isTouch_left;

};