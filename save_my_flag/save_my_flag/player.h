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
	D3DXVECTOR2 getSize();

	float posX;
	float posY;
	int radious;
	bool isDead;

};