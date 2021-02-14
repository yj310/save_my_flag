#pragma once
#include "page.h"
#include <d3dx9.h>
#include "player.h"


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

	Player player;
protected:

};