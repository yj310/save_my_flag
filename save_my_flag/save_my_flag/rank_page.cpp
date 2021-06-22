#include "global.h"
#include "rank_page.h"
#include <tchar.h>

#define BACKGROUND_WIDTH WINDOW_WIDTH
#define BACKGROUND_HEIGHT WINDOW_WIDTH

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 80

#define TEXT_RANK_X 770
#define TEXT_RANK_Y 250
#define TEXT_SCORE_X 1100	

#define BACK_BUTTON_WIDTH 40
#define BACK_BUTTON_HEIGHT 60
#define BACK_BUTTON_X 400
#define BACK_BUTTON_Y 100

RankPage::RankPage()
{
	classType = RANK_PAGE;

	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"³ª´®¹Ù¸¥°íµñ");

	int nHeight = -fontSize * nLogPixelsY / 72;
	D3DXCreateFont(g_pd3dDevice,
		nHeight,
		0,
		FW_BOLD,
		1,
		FALSE,
		DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS,
		DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_DONTCARE,
		g_strFont,
		&font);

	Load();

	PlayerInfo temp;
	for (int i = 0; i < 5; i++)
	{
		for (int j = i + 1; j < 6; j++)
		{
			if (ranking[i].playerScore < ranking[j].playerScore)
			{
				temp = ranking[i];
				ranking[i] = ranking[j];
				ranking[j] = temp;
			}
		}
	}

	Save();

	buttonState = TEX_BACK_NORMAL;
}

void RankPage::Load()
{
	FILE* fp = nullptr;

	fopen_s(&fp, "ranking.dat", "rt");

	if (fp != nullptr)
	{
		for (int i = 0; i < 5; ++i)
		{
			char name[128];
			int score;
			fscanf_s(fp, "%s %d", name, 128, &score);
			strcpy_s<128>(ranking[i].playerName, name);
			ranking[i].playerScore = score;
		}

		fclose(fp);
	}
}

void RankPage::Save()
{
	FILE* fp = nullptr;
	fopen_s(&fp, "ranking.dat", "wt");

	for (int i = 0; i < 5; ++i)
	{
		fprintf(fp, "%s %d\n", ranking[i].playerName, ranking[i].playerScore);
	}

	fclose(fp);
}

void RankPage::Update()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(hWnd, &pt);

	if (pt.x > BACK_BUTTON_X && pt.x<BACK_BUTTON_X+BACK_BUTTON_WIDTH && pt.y>BACK_BUTTON_Y && pt.y<BACK_BUTTON_Y+BACK_BUTTON_HEIGHT)
	{
		//if (buttonState == TEX_MAIN_BUTTON_NOMAL)
		//{
		//	//soundManager.sndOnButton->Reset();
		//	//soundManager.sndOnButton->Play(0, 0, 1);
		//}
		buttonState = TEX_BACK_BORDER;

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1 && inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateTitlePage();
		}
	}
	else
	{
		buttonState = TEX_BACK_NORMAL;
	}
}

void RankPage::Render()
{
	

	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;
	WCHAR text[256];

	TextureElement* element = textureManager.getTexture(TEX_RANK_PAGE);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = WINDOW_WIDTH;
	rc.bottom = WINDOW_HEIGHT;

	pos = { 0, 0, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

	//back
	element = textureManager.getTexture(buttonState);
	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = BACK_BUTTON_WIDTH;
	rc.bottom = BACK_BUTTON_HEIGHT;

	pos = { BACK_BUTTON_X, BACK_BUTTON_Y, 0 };

	element->sprite->Draw(element->texture, &rc, nullptr, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();

	
	
	for (int i = 0; i < 6; i++)
	{
		/*name*/
		for (int j = 0; j < strlen(ranking[i].playerName); j++)
		{
			rc.left = TEXT_RANK_X+ j*50;
			rc.top = TEXT_RANK_Y + i*120;
			rc.right = 15;
			rc.bottom = 15;

			if (i == 5) {
				rc.top = TEXT_RANK_Y + i * 120 +15;
			}

			_stprintf_s<256>(text, _T("%c"), ranking[i].playerName[j]);
			font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));

		}

		/*score*/

		rc.left = TEXT_SCORE_X;
		rc.top = TEXT_RANK_Y + i * 120;
		rc.right = 15;
		rc.bottom = 15;
		if (i == 5) {
			rc.top = TEXT_RANK_Y + i * 120+ 20;
		}

		_stprintf_s<256>(text, _T("%d"), ranking[i].playerScore);
		font->DrawText(NULL, text, -1, &rc, DT_NOCLIP,
			D3DXCOLOR(0.21f, 0.05f, 0.35f, 1.0f));
	}

	rc.left = TEXT_RANK_X;
	rc.top = TEXT_RANK_Y;

}