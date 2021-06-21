#include "global.h"
#include "rank_page.h"

#define BACKGROUND_WIDTH WINDOW_WIDTH
#define BACKGROUND_HEIGHT WINDOW_WIDTH

#define BUTTON_WIDTH 200
#define BUTTON_HEIGHT 80

RankPage::RankPage()
{
	HDC hDC = GetDC(NULL);
	int nLogPixelsY = GetDeviceCaps(hDC, LOGPIXELSY);
	ReleaseDC(NULL, hDC);

	int fontSize = 30;
	TCHAR g_strFont[256];
	wcscpy_s(g_strFont, 32, L"µÕ±Ù¸ð²Ã");

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

	if (pt.x > WINDOW_WIDTH * 0.9 - 100 && pt.x< WINDOW_WIDTH * 0.9 - 100 + BUTTON_WIDTH
		&& pt.y>WINDOW_HEIGHT * 0.9 && pt.y < WINDOW_HEIGHT * 0.9 + BUTTON_HEIGHT)
	{
		if (buttonState == TEX_MAIN_BUTTON_NOMAL)
		{
			//soundManager.sndOnButton->Reset();
			//soundManager.sndOnButton->Play(0, 0, 1);
		}
		buttonState = TEX_MAIN_BUTTON_MOUSEOVER;

		if (inputManager.prevKeyBuffer[VK_LBUTTON] == 1 && inputManager.keyBuffer[VK_LBUTTON] == 0)
		{
			pageManager.CreateTitlePage();
		}
	}
	else
	{
		buttonState = TEX_MAIN_BUTTON_NOMAL;
	}
}

void RankPage::Render()
{
	TextureElement* element = textureManager.getTexture(TEX_RANK_PAGE);

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