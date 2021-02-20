#pragma once

#include "tile.h"
#include <vector>
#include "game_over.h"
using namespace std;

class Player;

class GameSystem
{
public:
	GameSystem();
	void CreateMap();
	void GenerateTiles();
	void MakeNomalBrickTile(float x, float y);
	void MakeDamageTile(float x, float y);
	void Update();
	void Render();

	Player* player;
	vector<Tile*> tiles;
	GameOver* gameOverPage;
};