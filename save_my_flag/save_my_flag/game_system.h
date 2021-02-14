#pragma once
#include "player.h"
#include "tile.h"
#include <d3dx9.h>
using namespace std;

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