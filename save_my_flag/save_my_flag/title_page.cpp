#include "title_page.h"
#include "global.h"


#define START_BUTTON_WIDTH 300
#define START_BUTTON_HEIGHT 100
#define START_BUTTON_X WINDOW_WIDTH/2
#define START_BUTTON_Y 580
#define START_BUTTON_HALF_WIDTH START_BUTTON_WIDTH / 2
#define START_BUTTON_HALF_HEIGHT START_BUTTON_HEIGHT / 2


#define EXIT_BUTTON_WIDTH 300
#define EXIT_BUTTON_HEIGHT 100
#define EXIT_BUTTON_X WINDOW_WIDTH/2
#define EXIT_BUTTON_Y 700
#define EXIT_BUTTON_HALF_WIDTH EXIT_BUTTON_WIDTH / 2
#define EXIT_BUTTON_HALF_HEIGHT EXIT_BUTTON_HEIGHT / 2

#define CLOUD_A_X 1400
#define CLOUD_A_Y 80
#define CLOUD_A_WIDTH 415
#define CLOUD_A_HEIGHT 195

#define CLOUD_B_X 60
#define CLOUD_B_Y 200
#define CLOUD_B_WIDTH 340
#define CLOUD_B_HEIGHT 190

#define ENEMY_X 1800
#define ENEMY_Y 910
#define ENEMY_WIDTH 100
#define ENEMY_HEIGHT 100

TitlePage::TitlePage()
{

	classType = TITLE_PAGE;
	StartButtonState = TEX_START_BUTTON_NOMAL;
	ExitButtonState = TEX_EXIT_BUTTON_NOMAL;
	cloud_a_Y = CLOUD_A_Y;
	cloud_b_Y = CLOUD_B_Y;
	cloud_a_Y_direction = 1;
	cloud_b_Y_direction = 1;

	enemyA = new EnemyA(1700, 910, -1);
}

void TitlePage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	CloudUpdate();
	EnemyUpdate();
	StartButtonUpdate(pt);
	ExitButtonUpdate(pt);
	

}


void TitlePage::Render()
{
	BackgroundRender();
	TitleRender();
	StartButtonRender();
	ExitButtonRender();
	CloudRender();
	EnemyRender();
	TileRender();
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

	cloud_a_Y += cloud_a_Y_direction;
	cloud_b_Y += cloud_b_Y_direction;

	if (cloud_a_Y >= CLOUD_A_Y + 20)
	{
		cloud_a_Y_direction = -1;
	}
	if (cloud_a_Y <= CLOUD_A_Y - 20)
	{
		cloud_a_Y_direction = 1;
	}

	if (cloud_b_Y >= CLOUD_B_Y + 20)
	{
		cloud_b_Y_direction = -1;
	}
	if (cloud_b_Y <= CLOUD_B_Y - 20)
	{
		cloud_b_Y_direction = 1;
	}
}

void TitlePage::EnemyUpdate()
{
	//if(enemyA)
	enemyA->Update();

	if (enemyA->posX <= enemyA->width / 2)
	{
		enemyA->direction = 1;
		enemyA->state = TEX_ENEMY_C;
	}
	if (enemyA->posX >= WINDOW_WIDTH - enemyA->width / 2)
	{
		enemyA->direction = -1;
		enemyA->state = TEX_ENEMY_A;
	}


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
	rc.left = 0;	rc.top = 0;		rc.right = CLOUD_B_WIDTH;	rc.bottom = CLOUD_B_HEIGHT;
	pos = { CLOUD_B_X, cloud_b_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


	element = textureManager.getTexture(TEX_CLOUD_A);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;	rc.top = 0;		rc.right = CLOUD_A_WIDTH;	rc.bottom = CLOUD_A_HEIGHT;
	pos = { CLOUD_A_X, cloud_a_Y, 0 };
	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	element->sprite->End();


}

void TitlePage::EnemyRender()
{
	enemyA->Render();
}

void TitlePage::TileRender()
{
	TextureElement* element;

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;


	element = textureManager.getTexture(TEX_BRICK);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);
	rc.left = 0;	rc.top = 0;		rc.right = 100;	rc.bottom = 100;
	for (float i = 0; i < 20; i++)
	{
		pos = { i * 100, 910, 0 };
		element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));
	}
	element->sprite->End();
	

}