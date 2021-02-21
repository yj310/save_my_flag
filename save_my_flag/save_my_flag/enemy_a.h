#pragma once
#include <d3dx9.h>
#include "global.h"
#include "enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA(float x, float y, float direction);
	void Render() override;
	void Update() override;



	D3DXVECTOR2 getPos() override;
	void setPos(float x, float y) override;
	D3DXVECTOR2 getSize() override;
	void setSize(float width, float height) override;
	int getState() override;
	void setState(int state) override;
	float getDirection() override;
	void setDirection(float direction) override;
	float getSpeed() override;
	void setSpeed(float speed) override;

	int state;
	int state_count;

	float posX;
	float posY;

	float width;
	float height;

	float direction;
	float speed;
};