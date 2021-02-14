#include "game_system.h"
#include "global.h"
#include "tile.h"

GameSystem::GameSystem()
{
	CreateMap();
}

void GameSystem::CreateMap()
{
	GenerateTiles();
}

void GameSystem::GenerateTiles()
{
	for (int i = 0; i < 8; i++)
	{
		float posX, posY;
		posX = i * 100;
		posY = 910;
		Tile* tile = new Tile(posX, posY);
		tiles.push_back(tile);
	}
	Tile* tile = new Tile((tiles.size()-1)*100, 810);
	tiles.push_back(tile);

	int tiles_size = tiles.size();
	for (int i = tiles_size; i < tiles_size+10; i++)
	{
		float posX, posY;
		posX = i * 100;
		posY = 910;
		Tile* tile = new Tile(posX, posY);
		tiles.push_back(tile);
	}


}

void GameSystem::Update()
{

}

void GameSystem::Render()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Render();
	}
}