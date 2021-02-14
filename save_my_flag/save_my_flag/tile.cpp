#include "tile.h"
#include "global.h"

#define TILE_WIDTH 100
#define TILE_HEIGHT 100

Tile::Tile(float x, float y)
{
	posX = x;
	posY = y;
}

void Tile::Render()
{
	TextureElement* element = textureManager.getTexture(TEX_BRICK);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = TILE_WIDTH;
	rc.bottom = TILE_HEIGHT;

	//cen = { TILE_WIDTH / 2, TILE_HEIGHT / 2, 0 };
	pos = { posX, posY, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void Tile::Update()
{

}

D3DXVECTOR2 Tile::getPos()
{
	return { posX, posY };
}

D3DXVECTOR2 Tile::getSize()
{
	return { TILE_WIDTH, TILE_HEIGHT };
}