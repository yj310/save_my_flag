#pragma once
#include <d3dx9.h>
#include "global.h"
#include "enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA(float x, float y);
	void Render() override;
	void Update() override;

	D3DXVECTOR2 getPos() override;
	D3DXVECTOR2 getSize() override;

	int getState() override;


	// int state[4] = { TEX_ENEMY_A, TEX_ENEMY_B, TEX_ENEMY_C , TEX_ENEMY_D };
	int enemy_state;

	float posX;
	float posY;

	float enemy_width;
	float enemy_height;
};