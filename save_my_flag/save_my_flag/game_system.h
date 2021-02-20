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
	void MakeDropBrickTile(float x, float y, int group);
	void MakeDamageTile(float x, float y);
	void Update();
	void Render();
	void deleteData();
	
	int group_number;

	Player* player;
	vector<Tile*> tiles;
	GameOver* gameOverPage;
};