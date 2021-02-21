#include "game_over.h"
#include "global.h"
#include "enemy_a.h"
#include <ctime>


#define MAIN_BUTTON_WIDTH 300
#define MAIN_BUTTON_HEIGHT 100
#define MAIN_BUTTON_X WINDOW_WIDTH/2 - 330
#define MAIN_BUTTON_Y 860
#define MAIN_BUTTON_HALF_WIDTH MAIN_BUTTON_WIDTH / 2
#define MAIN_BUTTON_HALF_HEIGHT MAIN_BUTTON_HEIGHT / 2


#define RETURN_BUTTON_WIDTH 300
#define RETURN_BUTTON_HEIGHT 100
#define RETURN_BUTTON_X WINDOW_WIDTH/2 + 330
#define RETURN_BUTTON_Y 860
#define RETURN_BUTTON_HALF_WIDTH RETURN_BUTTON_WIDTH / 2
#define RETURN_BUTTON_HALF_HEIGHT RETURN_BUTTON_HEIGHT / 2

GameOver::GameOver()
{
	srand((unsigned int)time(NULL));
	randPage = TEX_GAME_OVER_A + rand() % 2;

	returnButtonState = TEX_RETURN_BUTTON_NOMAL;
	mainButtonState = TEX_MAIN_BUTTON_NOMAL;

}

void GameOver::Update()
{

	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);


	if (pt.x > MAIN_BUTTON_X - MAIN_BUTTON_HALF_WIDTH && pt.x < MAIN_BUTTON_X + MAIN_BUTTON_HALF_WIDTH
		&& pt.y > MAIN_BUTTON_Y - MAIN_BUTTON_HALF_HEIGHT && pt.y < MAIN_BUTTON_Y + MAIN_BUTTON_HALF_HEIGHT)
	{
		if (mainButtonState == TEX_MAIN_BUTTON_NOMAL)
		{
			mainButtonState = TEX_MAIN_BUTTON_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateTitlePage();
		}
	}
	else if (mainButtonState == TEX_MAIN_BUTTON_MOUSEOVER)
	{
		mainButtonState = TEX_MAIN_BUTTON_NOMAL;
	}



	if (pt.x > RETURN_BUTTON_X - RETURN_BUTTON_HALF_WIDTH && pt.x < RETURN_BUTTON_X + RETURN_BUTTON_HALF_WIDTH
		&& pt.y > RETURN_BUTTON_Y - RETURN_BUTTON_HALF_HEIGHT && pt.y < RETURN_BUTTON_Y + RETURN_BUTTON_HALF_HEIGHT)
	{
		if (returnButtonState == TEX_RETURN_BUTTON_NOMAL)
		{
			returnButtonState = TEX_RETURN_BUTTON_MOUSEOVER;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateFirstGamePage();
		}
	}
	else if (returnButtonState == TEX_RETURN_BUTTON_MOUSEOVER)
	{
		returnButtonState = TEX_RETURN_BUTTON_NOMAL;
	}



}

void GameOver::Render()
{
	TextureElement* element;

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(randPage);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(mainButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = MAIN_BUTTON_WIDTH;
	rc.bottom = MAIN_BUTTON_HEIGHT;

	cen = { MAIN_BUTTON_HALF_WIDTH, MAIN_BUTTON_HALF_HEIGHT, 0 };
	pos = { MAIN_BUTTON_X, MAIN_BUTTON_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(returnButtonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = RETURN_BUTTON_WIDTH;
	rc.bottom = RETURN_BUTTON_HEIGHT;

	cen = { RETURN_BUTTON_HALF_WIDTH, RETURN_BUTTON_HALF_HEIGHT, 0 };
	pos = { RETURN_BUTTON_X, RETURN_BUTTON_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();




	element = textureManager.getTexture(TEX_GOLD_A);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 80;

	pos = { 600, 500, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();




	element = textureManager.getTexture(TEX_GOLD_A);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 80;

	pos = { 600, 500, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_X);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 700, 500 - 10, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();




	element = textureManager.getTexture(TEX_ENEMY_A_3);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 600, 650, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	element = textureManager.getTexture(TEX_X);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 700, 650, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();


}