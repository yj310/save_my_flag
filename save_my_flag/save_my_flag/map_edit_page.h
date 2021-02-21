#pragma once
#include "page.h"

class MapEditPage : public Page
{
public:
	MapEditPage();
	void Update() override;
	void Render() override;

	int nomalBrickState;
	int dropBrickState;
	int damageTileState;
	int clickState;
};