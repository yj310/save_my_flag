#pragma once
#include "global.h"

class Player
{
public:
	Player();

	void Update();
	void Render();

	D3DXVECTOR2 getPos();
	int getRadious();
	bool getIsDead();

	float posX;
	float posY;
	int radious;
	float width;
	float height;
	bool isDead;

};