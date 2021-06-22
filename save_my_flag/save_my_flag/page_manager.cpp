#include "page_manager.h"
#include "global.h"
#include "title_page.h"
#include "first_game_page.h"
#include "map_edit_page.h"
#include "rank_page.h"


void PageManager::CreateTitlePage()
{
	if (currentPage != nullptr) 
	{
		prevPage = currentPage;

		if (prevPage->classType == TITLE_PAGE)
		{
			soundManager.BGMTitleStage->Stop();
		}
		if (prevPage->classType == FIRST_GAME_PAGE)
		{
			soundManager.BGMFirstStage->Stop();
			gameSystem.deleteData();
		}
		if (prevPage->classType == RANK_PAGE)
		{
			soundManager.BGMRankStage->Stop();
		}
		delete currentPage;
	}

	soundManager.BGMTitleStage->Reset();
	soundManager.BGMTitleStage->Play(0, DSBPLAY_LOOPING, 1);
	TitlePage* newPage = new TitlePage();
	currentPage = newPage;

}

void PageManager::CreateFirstGamePage()
{
	if (currentPage != nullptr)
	{
		prevPage = currentPage;

		if (prevPage->classType == TITLE_PAGE)
		{
			soundManager.BGMTitleStage->Stop();
		}
		if (prevPage->classType == FIRST_GAME_PAGE)
		{
			soundManager.BGMFirstStage->Stop();
			gameSystem.deleteData();
		}
		if (prevPage->classType == RANK_PAGE)
		{
			soundManager.BGMRankStage->Stop();
		}
		delete currentPage;
	}

	soundManager.BGMFirstStage->Reset();
	soundManager.BGMFirstStage->Play(0, DSBPLAY_LOOPING, 1);
	FirstGamePage* newPage = new FirstGamePage();
	currentPage = newPage;
}

void PageManager::CreateMapEditPage()
{
	if (currentPage != nullptr)
	{
		if (currentPage->classType == FIRST_GAME_PAGE)
		{
			gameSystem.deleteData();
		}
		delete currentPage;
	}

	MapEditPage* newPage = new MapEditPage();
	currentPage = newPage;
}

void PageManager::CreateRankingPage()
{
	if (currentPage != nullptr)
	{
		prevPage = currentPage;

		if (prevPage->classType == TITLE_PAGE)
		{
			soundManager.BGMTitleStage->Stop();
		}
		if (prevPage->classType == FIRST_GAME_PAGE)
		{
			soundManager.BGMFirstStage->Stop();
			gameSystem.deleteData();
		}
		if (prevPage->classType == RANK_PAGE)
		{
			soundManager.BGMRankStage->Stop();
		}
		delete currentPage;
	}
	soundManager.BGMRankStage->Reset();
	soundManager.BGMRankStage->Play(0, DSBPLAY_LOOPING, 1);
	RankPage* newPage = new RankPage();
	currentPage = newPage;
}

void PageManager::Update()
{
	if (currentPage != nullptr)
	{
		currentPage->Update();
		/*if (pageState == FadeOut)
		{

			if (FadingCount >= 50)
			{
				//pageState = FadeIn;
			}
		}
		else if (pageState == FadeIn)
		{

			if (FadingCount <= 0)
			{
				//pageState = Playing;
			}
		}
		else
		{
			currentPage->Update();
		}*/

	}

}

void PageManager::Render()
{
	if (currentPage != nullptr)
	{
		currentPage->Render();
		/*if (pageState == FadeOut)
		{
			//prevPage->Render();
		}
		else if (pageState == FadeIn)
		{
			currentPage->Render();
		}
		else
		{
			currentPage->Render();
		}*/
	}
}