
#include "game_clear.h"
#include "global.h"
#include "enemy_a.h"
#include "player.h"
#include <d3dx9.h>
#include <ctime>
#include <string>
#include <tchar.h>


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


#define TEXT_X 600
#define TEXT_X2 900

#define COIN_Y 400

#define SCORE_X 700
#define SCORE_Y 600

#define NAME_X 700
#define NAME_Y 720

#define ENTERTIMER 40

GameClear::GameClear()
{
	
	returnButtonState = TEX_RETURN_BUTTON_NOMAL;
	mainButtonState = TEX_MAIN_BUTTON_NOMAL;

	//ID3DXFont* font1;


	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);
	int fontSize = 27;
	int nHeight = -fontSize * nLogPixelsY / 72;
	TCHAR g_strFont[LF_FACESIZE];
	wcscpy_s(g_strFont, 32, L"³ª´®¹Ù¸¥°íµñ");
	D3DXCreateFont(g_pd3dDevice,            // D3D device
		nHeight,               // Height
		0,                     // Width
		FW_BOLD,               // Weight
		1,                     // MipLevels, 0 = autogen mipmaps
		FALSE,                 // Italic
		DEFAULT_CHARSET,       // CharSet
		OUT_DEFAULT_PRECIS,    // OutputPrecision
		DEFAULT_QUALITY,       // Quality
		DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
		g_strFont,              // pFaceName
		&font1);

	fontSize = 15;
	nHeight = -fontSize * nLogPixelsY / 72;
	D3DXCreateFont(g_pd3dDevice,            // D3D device
		nHeight,               // Height
		0,                     // Width
		FW_BOLD,               // Weight
		1,                     // MipLevels, 0 = autogen mipmaps
		FALSE,                 // Italic
		DEFAULT_CHARSET,       // CharSet
		OUT_DEFAULT_PRECIS,    // OutputPrecision
		DEFAULT_QUALITY,       // Quality
		DEFAULT_PITCH | FF_DONTCARE, // PitchAndFamily
		g_strFont,              // pFaceName
		&font2);

	enterTimer = ENTERTIMER;
}

void GameClear::Update()
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

	for (int i = 'A'; i < 'Z'; i++)
	{
		if (inputManager.prevKeyBuffer[i] == 1
			&& inputManager.keyBuffer[i] == 0)
		{
			cname.push_back((char)i);
		}
	}

	if (inputManager.prevKeyBuffer[VK_BACK] == 1
		&& inputManager.keyBuffer[VK_BACK] == 0)
	{
		if (cname.size() > 0) {
			cname.pop_back();
		}

	}

	if (enterTimer > -1 * ENTERTIMER)
	{
		enterTimer--;
	}
	else
	{
		enterTimer = ENTERTIMER;
	}
}

void GameClear::Render()
{
	TextureElement* element;

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(TEX_GAME_CLEAR);
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

	pos = { TEXT_X, COIN_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();





	element = textureManager.getTexture(TEX_X);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 100;
	rc.bottom = 100;

	pos = { 700, COIN_Y - 5, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();


	/*coin*/
	WCHAR text[256];

	rc.left = TEXT_X2;
	rc.top = COIN_Y + 10;
	rc.right = 15;
	rc.bottom = 15;

	int coin = gameSystem.player->getCoin();
	_stprintf_s<256>(text, _T("%d"), coin);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));


	/*score txt*/
	element = textureManager.getTexture(TEX_SCORE);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 160;
	rc.bottom = 50;

	pos = { SCORE_X, SCORE_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	/*score*/
	rc.left = TEXT_X2;
	rc.top = SCORE_Y - 50;
	rc.right = 15;
	rc.bottom = 15;

	int score = gameSystem.player->score;
	_stprintf_s<256>(text, _T("%d"), score);
	font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
		D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));


	/*name txt*/
	element = textureManager.getTexture(TEX_NAME);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = 160;
	rc.bottom = 50;

	pos = { NAME_X, NAME_Y, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();



	/*´Ð³×ÀÓ*/
	for (int i = 0; i < cname.size(); i++)
	{
		rc.left = TEXT_X2 + i * 35;
		rc.top = NAME_Y - 50;
		rc.right = 750 + i * 35;
		rc.bottom = 15;
		_stprintf_s<256>(text, _T(" %c"), cname[i]);
		font1->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));
	}

	if (enterTimer <= 25)
	{
		rc.left = TEXT_X2;
		rc.top = NAME_Y;
		rc.right = 15;
		rc.bottom = 15;
		_stprintf_s<256>(text, _T("press input your name!"));
		font2->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.0f, 0.0f, 0.0f, 0.1f));
	}

}