#pragma once
#include <d3dx9.h>
class Gold
{
public:
	Gold(float x, float y);
	void Render();
	void Update();

	float posX;
	float posY;
	float width;
	float height;

	int state_count;
	int state;

	void setPos(float x, float y);
	D3DXVECTOR2 getPos();
	void setSize(float width, float height);
	D3DXVECTOR2 getSize();
	void setState(int state);
	int getState();
};