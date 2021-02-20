#pragma once
#include <d3dx9.h>

#define TILE_WIDTH 100
#define TILE_HEIGHT 100

class Tile
{
public:

	virtual void Render() = 0;
	virtual void Update() = 0;

	float posX;
	float posY;
	int width;
	int height;

	int tileType;
	int group;
	//bool isDown;

	D3DXVECTOR2 getPos() { return { posX, posY }; }
	void setPos(float x, float y) { posX = x; posY = y; }
	D3DXVECTOR2 getSize() { return { TILE_WIDTH, TILE_HEIGHT }; }
	int getTileType() { return tileType; }
	void setTileType(int tileType) { this->tileType = tileType; }
};