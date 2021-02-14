#pragma once
#include <d3dx9.h>
class Tile
{
public:
	Tile(float x, float y);
	void Render();
	void Update();

	float posX;
	float posY;

	D3DXVECTOR2 getPos();
	D3DXVECTOR2 getSize();
};