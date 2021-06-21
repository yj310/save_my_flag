#include "flag.h"
#include "global.h"
#include "player.h"
#include <d3dx9.h>

Flag::Flag(float x, float y)
{
	posX = x;
	posY = y;

	isGo = false;
	width = 120;
	height = 300;
}

void Flag::Update()
{
	if (gameSystem.player->posX >= 75*100 && posX<=95*100)
	{
		if (posX< gameSystem.player->posX + 500 + gameSystem.player->speed )
		{
			posX = gameSystem.player->posX + 500 + gameSystem.player->speed;
		}
		
		
	}
	
	
}

void Flag::Render()
{
	TextureElement* element = textureManager.getTexture(TEX_FLAG);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = width;
	rc.bottom = height;

	//pos = { posX ,posY,0 };
	pos = { gameSystem.getPrintPos(posX, posY).x, gameSystem.getPrintPos(posX, posY).y, 0 };
	
	
	
	

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

}

D3DXVECTOR2 Flag::getSize()
{
	return D3DXVECTOR2(width, height);
}