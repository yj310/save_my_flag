#include "title_page.h"
#include "global.h"


#define START_BUTTON_WIDTH 320
#define START_BUTTON_HEIGHT 110
#define START_BUTTON_X WINDOW_WIDTH / 2
#define START_BUTTON_Y 600
#define START_BUTTON_HALF_WIDTH START_BUTTON_WIDTH / 2
#define START_BUTTON_HALF_HEIGHT START_BUTTON_HEIGHT / 2

TitlePage::TitlePage()
{
	D3DXCreateSprite(g_pd3dDevice, &spr);

	classType = TITLE_PAGE;
	StartButtonState = TEX_START_BUTTON_NOMAL;

	//gameSystem.deleteData();
	
	tex = textureManager.getTexture(TEX_TITLE_PAGE_TITLE);
}

void TitlePage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	StartButtonUpdate(pt);

}


void TitlePage::Render()
{
	//BackgroundRender();
	StartButtonRender();

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
			//pageManager.CreateStartPlayerPage();
		}
	}
	else if (StartButtonState == TEX_START_BUTTON_BORD)
	{
		StartButtonState = TEX_START_BUTTON_NOMAL;
	}
}



/* Render */
void TitlePage::BackgroundRender()
{
	TextureElement* element = new TextureElement();
	D3DXCreateSprite(g_pd3dDevice, &element->sprite);
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element->texture = textureManager.getTexture(TEX_TITLE_PAGE_BACKGROUND);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(*element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void TitlePage::StartButtonRender()
{

	//TextureElement* element = new TextureElement();
	//D3DXCreateSprite(g_pd3dDevice, &element->sprite);
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	//element->texture = textureManager.getTexture(TEX_TITLE_PAGE_TITLE);
	spr->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	spr->Draw(*tex, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	spr->End();


}