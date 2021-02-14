#include "game_system.h"
#include "global.h"
#include "tile.h"

GameSystem::GameSystem()
{

}

void GameSystem::CreateMap()
{
	
}

void GameSystem::GenerateTiles()
{
	for (int i = 0; i < 40; i++)
	{
		Tile* tile = new Tile(i * 100, 910);
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