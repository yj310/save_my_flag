#pragma once
#include "cloud_a.h"
#include "global.h"


#define CLOUD__WIDTH 415
#define CLOUD__HEIGHT 195


CloudA::CloudA(float x, float y, int state, int type)
{
	posX = x;
	posY = y;
	_state = state;
	img_type = type;
	cloud_Y_direction = 1;

	speed = 10;
}

void CloudA::Update()
{
	

	if (_state == normal)
	{
		Normal();
	}
	else if (_state == down)
	{
		Down();
	}
	else if (_state == updown)
	{
		UpDown();
	}
}

void CloudA::Normal()
{
	posY += cloud_Y_direction;

	if (posY >= posY + 20)
	{
		cloud_Y_direction = -1;
	}
	if (posY <= posY - 20)
	{
		cloud_Y_direction = 1;
	}
}

void CloudA::Down()
{
	posY += speed;
}

void CloudA::UpDown()
{
	Down();
	if (posY < WINDOW_HEIGHT + 500)
	{
		speed * -1;
	}
}

void CloudA::Render()
{
	TextureElement* element = textureManager.getTexture(_state);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = CLOUD__WIDTH;
	rc.bottom = CLOUD__HEIGHT;

	pos = { posX, posY, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}