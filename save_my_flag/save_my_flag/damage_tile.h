#pragma once
#include "tile.h"
#include <d3dx9.h>
#include "global.h"

class DamageTile :public Tile
{
public:
	DamageTile(float x, float y);
	void Update() override;
	void Render() override;
};