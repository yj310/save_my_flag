#pragma once
#include "page.h"
#include <d3dx9.h>
#include "player.h"
#include "game_over.h"
#include "game_clear.h"


class FirstGamePage : public Page
{
public:

	FirstGamePage();
	void Update() override;
	void Render() override;

	/* Update */
	void BackgroundUpdate();
	
	/* Render */
	void BackgroundRender();

	GameOver gameOver;
	GameClear gameClear;

protected:

};