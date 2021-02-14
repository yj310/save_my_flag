#pragma once
#include <d3dx9.h>
class Tile
{
public:
	Tile();
	void Render();
	void Update();

	float posX;
	float posY;
	float width;
	float height;

	D3DXVECTOR2 getPos();
	D3DXVECTOR2 getSize();
};