#include "tile.h"
#pragma once
#include <d3dx9.h>
#include "global.h"

class BrickNormal :public Tile
{
public:
	BrickNormal(float x, float y);
	void Update();
	void Render();
};