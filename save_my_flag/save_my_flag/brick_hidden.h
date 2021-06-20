#pragma once
#include "tile.h"
#include <d3dx9.h>
#include "global.h"

class BrickHidden :public Tile
{
public:
	BrickHidden(float x, float y);
	void Update() override;
	void Render() override;


};