#pragma once
#include <d3dx9.h>


class Flag
{
public:
	Flag(float x, float y);
	void Update();
	void Render();

	float posX, posY;
	float width, height;

	bool isGo;

	D3DXVECTOR2 getPos();
	D3DXVECTOR2 getSize();
};