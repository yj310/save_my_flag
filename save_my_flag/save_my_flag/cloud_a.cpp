
#include "cloud_a.h"
#include "global.h"


#define CLOUD_WIDTH 415
#define CLOUD_HEIGHT 195


CloudA::CloudA(float x, float y, int state, int type)
{

	posX = x;
	posY = y;
	start_posY = posY;
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
	if (_state == down)
	{
		Down();
	}
	if (_state == updown)
	{
		UpDown();
	}
}

void CloudA::Normal()
{
	posY += cloud_Y_direction;

	if (posY >= start_posY + 20)
	{
		cloud_Y_direction = -1;
	}
	if (posY <= start_posY - 20)
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
	TextureElement* element = textureManager.getTexture(img_type);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = CLOUD_WIDTH;
	rc.bottom = CLOUD_HEIGHT;

	pos = { gameSystem.getPrintPos(posX, posY).x, gameSystem.getPrintPos(posX, posY).y, 0};

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}


D3DXVECTOR2 CloudA::getPos()
{
	return { posX, posY };
}

void CloudA::setPos(float x, float y)
{
	posX = x;
	posY = y;
}

D3DXVECTOR2 CloudA::getSize()
{
	return { width, height };
}

void CloudA::setSize(float width, float height)
{
	this->width = width;
	this->height = height;
}

int CloudA::getState()
{
	return _state;
}

void CloudA::setState(int state)
{
	this->_state = state;
}

float CloudA::getSpeed()
{
	return speed;
}

void CloudA::setSpeed(float speed)
{
	this->speed = speed;
}

