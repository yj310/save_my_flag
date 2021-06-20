#include "map_edit_page.h"
#include "global.h"

MapEditPage::MapEditPage()
{
	nomalBrickState = 255;
	dropBrickState = 255;
	damageTileState = 255;
	clickState = -1;
}

void MapEditPage::Update()
{

	/*POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	if (pt.x > 0 && pt.x < 100
		&& pt.y > 0 && pt.y < 100)
	{
		if (nomalBrickState == 255)
		{
			nomalBrickState = 200;
		}
		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			if (clickState != NOMAL_BRICK)
				clickState = NOMAL_BRICK;
			else
				clickState = -1;
		}
	}
	else if (clickState != NOMAL_BRICK)
	{
		nomalBrickState = 255;
	}



	if (pt.x > 100 && pt.x < 200
		&& pt.y > 0 && pt.y < 100)
	{
		if (dropBrickState == 255)
		{
			dropBrickState = 200;
		}
		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			if (clickState != DROP_BRICK)
				clickState = DROP_BRICK;
			else
				clickState = -1;
		}
	}
	else if (clickState != DROP_BRICK)
	{
		dropBrickState = 255;
	}



	if (pt.x > 200 && pt.x < 300
		&& pt.y > 0 && pt.y < 100)
	{
		if (damageTileState == 255)
		{
			damageTileState = 200;
		}
		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			if (clickState != DAMAGE_TILE)
				clickState = DAMAGE_TILE;
			else
				clickState = -1;
		}
	}
	else if (clickState != DAMAGE_TILE)
	{
		damageTileState = 255;
	}*/


}

void MapEditPage::Render()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;


	element = textureManager.getTexture(TEX_FIRST_GAME_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_BRICK);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, nomalBrickState, nomalBrickState, nomalBrickState));
	element->sprite->End();


	element = textureManager.getTexture(TEX_BRICK);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 100, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, dropBrickState, 0, dropBrickState));
	element->sprite->End();


	element = textureManager.getTexture(TEX_DAMAGE_TILE);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 200, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, damageTileState, damageTileState, damageTileState));
	element->sprite->End();

}