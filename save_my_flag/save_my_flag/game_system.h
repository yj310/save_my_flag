#pragma once

#include "tile.h"
#include <vector>
using namespace std;

class Player;

class GameSystem
{
public:
	GameSystem();
	void CreateMap();
	void GenerateTiles();

	void Update();
	void Render();

	Player* player;
	vector<Tile*> tiles;
};