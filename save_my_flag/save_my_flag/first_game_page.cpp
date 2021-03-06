#include "first_game_page.h"
#include "global.h"	
#include "player.h"

FirstGamePage::FirstGamePage()
{
	classType = FIRST_GAME_PAGE;
	gameSystem.CreateMap();
}

void FirstGamePage::Update()
{
	
	BackgroundUpdate();
	gameSystem.Update();
	if (gameSystem.player->isDead)
	{
		gameOver.Update();
	}
	else if (gameSystem.player->isClear)
	{
		gameClear.Update();
	}
}

void FirstGamePage::Render()
{
	BackgroundRender();
	gameSystem.Render();
	if (gameSystem.player->isDead)
	{
		gameOver.Render();
	}
	else if (gameSystem.player->isClear)
	{
		gameClear.Render();
	}
}

void FirstGamePage::BackgroundUpdate()
{

}

void FirstGamePage::BackgroundRender()
{
	TextureElement* element = textureManager.getTexture(TEX_FIRST_GAME_PAGE_BACKGROUND);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}