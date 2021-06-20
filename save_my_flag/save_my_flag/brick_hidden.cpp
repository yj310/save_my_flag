#include "brick_hidden.h"
#include "global.h"


BrickHidden::BrickHidden(float x, float y)
{
	isCollided = false;
	startY = y;
	posX = x;
	posY = y;
	tileType = HIDDEN_BRICK;
}

void BrickHidden::Update()
{
	
}

void BrickHidden::Render()
{
	if (isCollided) {
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
		pos = { gameSystem.getPrintPos(posX, posY).x, gameSystem.getPrintPos(posX, posY).y, 0 };

		element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();
	}
	else {
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
		pos = { gameSystem.getPrintPos(posX, posY).x, gameSystem.getPrintPos(posX, posY).y, 0 };

		element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();
	}
	
}