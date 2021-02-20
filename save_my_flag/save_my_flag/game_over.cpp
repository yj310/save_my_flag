#include "game_over.h"
#include "global.h"
#include <ctime>

GameOver::GameOver()
{
	srand((unsigned int)time(NULL));
	randPage = TEX_GAME_OVER_A + rand() % 2;
}

void GameOver::Update()
{

}

void GameOver::Render()
{
	TextureElement* element = textureManager.getTexture(randPage);

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