#include "gold.h"
#include "global.h"

Gold::Gold(float x, float y)
{
	posX = x;
	posY = y;

	width = 100;
	height = 80;
	isTouch = false;

	state_count = 0;
	state = TEX_GOLD_A;

}

void Gold::Render()
{
	if (!isTouch)
	{
		TextureElement* element = textureManager.getTexture(state);

		RECT rc;
		D3DXVECTOR3 pos;
		D3DXVECTOR3 cen;

		element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

		rc.left = 0;
		rc.top = 0;
		rc.right = width;
		rc.bottom = height;

		cen = { width / 2, height, 0 };
		pos = { gameSystem.getPrintPos(posX, posY).x, gameSystem.getPrintPos(posX, posY).y, 0 };

		element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

		element->sprite->End();
	}
	
}

void Gold::Update()
{
	state_count++;
	if (state_count >= 5)
	{
		state_count = 0;
		if (state < TEX_GOLD_G)
		{
			state += 1;
		}
		else
		{
			state = TEX_GOLD_A;
		}
	}
	
}

void Gold::setPos(float x, float y)
{
	posX = x;
	posY = y;
}

D3DXVECTOR2 Gold::getPos()
{
	return { posX, posY };
}

int Gold::getRadious()
{
	return 40;
}

void Gold::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

D3DXVECTOR2 Gold::getSize()
{
	return { width, height };
}

void Gold::setState(int state)
{
	this->state = state;
}

int Gold::getState()
{
	return state;
}