#pragma once
#include "tile.h"
#include <d3dx9.h>
#include "global.h"

class BrickDrop :public Tile
{
public:
	BrickDrop(float x, float y, int tile_group);
	void Update() override;
	void Render() override;

	
};