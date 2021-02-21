#pragma once

#include "tile.h"
#include <vector>
#include "game_over.h"
#include "enemy.h"
using namespace std;

class Player;

class GameSystem
{
public:
	GameSystem();
	void CreateMap();
	void GenerateTiles();
	void GenerateEnemys();
	void MakeNomalBrickTile(float x, float y);
	void MakeDropBrickTile(float x, float y, int group);
	void MakeDamageTile(float x, float y);
	void MakeEnemyA(float x, float y, float direction);
	void Update();
	void Render();
	void deleteData();
	D3DXVECTOR2 getPrintPos(float x, float y);
	
	int group_number;

	Player* player;
	vector<Tile*> tiles;
	vector<Enemy*> enemys;
	GameOver* gameOverPage;
};