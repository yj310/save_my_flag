#pragma once
#include <d3dx9.h>

class Enemy
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	int classType;

	float posX;
	float posY;
	float radious;
	float width;
	float height;
	float direction;
	float speed;
	float gravity;

	int state;
	int state_count;


	bool isTouch_top;
	bool isTouch_bottom;
	bool isTouch_right;
	bool isTouch_left;


	D3DXVECTOR2 getPos() { return { posX, posY }; }
	void setPos(float x, float y) { this->posX = x; this->posY = y; }
	D3DXVECTOR2 getSize() { return { width, height }; }
	void setSize(float width, float height) { this->width = width; this->height = height; }
	int getState() { return state; }
	void setState(int state) { this->state = state; }
	float getDirection() { return direction; }
	void setDirection(float direction) { this->direction = direction; }
	float getSpeed() { return speed; }
	void setSpeed(float speed) { this->speed = speed; }
	float getRadious() { return radious; }
	void setRadious(float radious) { this->radious = radious; }


	void Gravity()
	{
		if (!isTouch_bottom)
			posY += gravity;
	}
};