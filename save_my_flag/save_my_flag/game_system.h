#pragma once

#include "tile.h"
#include <vector>
#include "game_over.h"
#include "enemy.h"
#include "cloud.h"
using namespace std;

class Player;

class GameSystem
{
public:
	GameSystem();
	void CreateMap();
	void GenerateTiles();
	void GenerateEnemys();
	void GenerateClouds();
	void MakeNomalBrickTile(float x, float y);
	void MakeDropBrickTile(float x, float y, int group);
	void MakeDamageTile(float x, float y);
	void MakeEnemyA(float x, float y, float direction);
	void MakeCloud(float x, float y, int state, int type);
	void Update();
	void Render();
	void deleteData();
	D3DXVECTOR2 getPrintPos(float x, float y);
	
	int group_number;
	enum cloud_state
	{
		normal,
		down,
		updown
	};
	Player* player;
	vector<Tile*> tiles;
	vector<Enemy*> enemys;
	vector<Cloud*> clouds;
	GameOver* gameOverPage;
};