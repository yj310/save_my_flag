#pragma once
#include "fading.h"

class Page;

class PageManager
{
public:

	enum State
	{
		FadeIn,
		FadeOut,
		Playing
	};

	Page* prevPage;
	Page* currentPage;
	Page* nextPage;

	Fading fading;
	State pageState;
	int FadingCount;


	void CreateTitlePage();
	void CreateFirstGamePage();

	void Update();
	void Render();


};