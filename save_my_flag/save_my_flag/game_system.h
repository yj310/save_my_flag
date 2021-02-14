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
	void MakeTile(float x, float y);
	void Update();
	void Render();

	Player* player;
	vector<Tile*> tiles;
};