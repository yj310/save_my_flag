#include "title_page.h"
#include "global.h"


#define START_BUTTON_WIDTH 400
#define START_BUTTON_HEIGHT 150
#define START_BUTTON_X WINDOW_WIDTH/2
#define START_BUTTON_Y 600
#define START_BUTTON_HALF_WIDTH START_BUTTON_WIDTH / 2
#define START_BUTTON_HALF_HEIGHT START_BUTTON_HEIGHT / 2


#define EXIT_BUTTON_WIDTH 400
#define EXIT_BUTTON_HEIGHT 150
#define EXIT_BUTTON_X WINDOW_WIDTH/2
#define EXIT_BUTTON_Y 800
#define EXIT_BUTTON_HALF_WIDTH EXIT_BUTTON_WIDTH / 2
#define EXIT_BUTTON_HALF_HEIGHT EXIT_BUTTON_HEIGHT / 2

TitlePage::TitlePage()
{

	classType = TITLE_PAGE;
	StartButtonState = TEX_START_BUTTON_NOMAL;
	ExitButtonState = TEX_EXIT_BUTTON_NOMAL;
	cloud_a_Y = 80;
	cloud_b_Y = 200;
	enemy_X = 1800;
	enemy_state = TEX_ENEMY_A;
	enemy_count = 0;
}

void TitlePage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	StartButtonUpdate(pt);
	ExitButtonUpdate(pt);
	CloudUpdate();
	EnemyUpdate();

}


void TitlePage::Render()
{
	BackgroundRender();
	TitleRender();
	StartButtonRender();
	ExitButtonRender();
	CloudRender();
	EnemyRender();

}

/* Update*/
void TitlePage::StartButtonUpdate(POINT pt)
{
	if (pt.x > START_BUTTON_X - START_BUTTON_HALF_WIDTH && pt.x < START_BUTTON_X + START_BUTTON_HALF_WIDTH
		&& pt.y > START_BUTTON_Y - START_BUTTON_HALF_HEIGHT && pt.y < START_BUTTON_Y + START_BUTTON_HALF_HEIGHT)
	{
		if (StartButtonState == TEX_START_BUTTON_NOMAL)
		{
			StartButtonState = TEX_START_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateFirstGamePage();
		}
	}
	else if (StartButtonState == TEX_START_BUTTON_BORD)
	{
		StartButtonState = TEX_START_BUTTON_NOMAL;
	}
}

void TitlePage::ExitButtonUpdate(POINT pt)
{
	if (pt.x > EXIT_BUTTON_X - EXIT_BUTTON_HALF_WIDTH && pt.x < EXIT_BUTTON_X + EXIT_BUTTON_HALF_WIDTH
		&& pt.y > EXIT_BUTTON_Y - EXIT_BUTTON_HALF_HEIGHT && pt.y < EXIT_BUTTON_Y + EXIT_BUTTON_HALF_HEIGHT)
	{
		if (ExitButtonState == TEX_EXIT_BUTTON_NOMAL)
		{
			ExitButtonState = TEX_EXIT_BUTTON_BORD;
		}


		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1
			&& inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			PostQuitMessage(0);
		}
	}
	else if (ExitButtonState == TEX_EXIT_BUTTON_BORD)
	{
		ExitButtonState = TEX_EXIT_BUTTON_NOMAL;
	}
}

void TitlePage::CloudUpdate()
{

}

void TitlePage::EnemyUpdate()
{

}


/* Render */
void TitlePage::BackgroundRender()
{

	TextureElement* element = textureManager.getTexture(TEX_TITLE_PAGE_BACKGROUND);

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

void TitlePage::TitleRender()
{

	TextureElement* element = textureManager.getTexture(TEX_TITLE_PAGE_TITLE);
	
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

void TitlePage::StartButtonRender()
{
	TextureElement* element = textureManager.getTexture(StartButtonState);
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = START_BUTTON_WIDTH;
	rc.bottom = START_BUTTON_HEIGHT;

	pos = { START_BUTTON_X, START_BUTTON_Y, 0};
	cen = { START_BUTTON_HALF_WIDTH, START_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void TitlePage::ExitButtonRender()
{
	TextureElement* element = textureManager.getTexture(ExitButtonState);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = EXIT_BUTTON_WIDTH;
	rc.bottom = EXIT_BUTTON_HEIGHT;

	pos = { EXIT_BUTTON_X, EXIT_BUTTON_Y, 0 };
	cen = { EXIT_BUTTON_HALF_WIDTH, EXIT_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void TitlePage::CloudRender()
{
	TextureElement* element;

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;


	element = textureManager.getTexture(TEX_CLOUD_B);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;	rc.top = 0;		rc.right = 340;	rc.bottom = 190;
	pos = { 80, cloud_b_Y, 0 };
	element->sprite->Draw(element->texture, &rc, false, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	element = textureManager.getTexture(TEX_CLOUD_A);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;	rc.top = 0;		rc.right = 415;	rc.bottom = 195;
	pos = { 1400, cloud_a_Y, 0 };
	element->sprite->Draw(element->texture, &rc, false, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


}

void TitlePage::EnemyRender()
{
	TextureElement* element = textureManager.getTexture(ExitButtonState);

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = EXIT_BUTTON_WIDTH;
	rc.bottom = EXIT_BUTTON_HEIGHT;

	pos = { EXIT_BUTTON_X, EXIT_BUTTON_Y, 0 };
	cen = { EXIT_BUTTON_HALF_WIDTH, EXIT_BUTTON_HALF_HEIGHT, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}