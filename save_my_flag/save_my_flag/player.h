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

	int posX;
	int posY;
	int radious;
	int width;
	int height;
	bool isDead;

};