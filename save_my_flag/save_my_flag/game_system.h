#pragma once
#include "player.h"

class GameSystem
{
public:
	GameSystem();
	void CreateMap();

	void Update();
	void Render();

	Player* player;
};