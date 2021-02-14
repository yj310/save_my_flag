#include "game_system.h"
#include "global.h"
#include "player.h"
#include "tile.h"

GameSystem::GameSystem()
{
	CreateMap();
}

void GameSystem::CreateMap()
{
	GenerateTiles();
}

void GameSystem::MakeTile(float x, float y)
{
	Tile* tile = new Tile(x, y);
	tiles.push_back(tile);
}

void GameSystem::GenerateTiles()
{
	float posX, posY ;
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = 910 + j*100;
			MakeTile(posX, posY);
		}
	}
	MakeTile(15 * 100, 910 - 100 * 1);

	/*떨어지는 블럭*/
	for (int i = 16; i < 19; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = 910 + j * 100;
			MakeTile(posX, posY);
		}
	}

	for (int i = 19; i < 19+19; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = 910 + j * 100;
			MakeTile(posX, posY);
		}
	}
	for (int i = 35; i < 35 + 3; i++)
	{
		for (int j = 1; j < 1+3; j++)
		{
			if ((i == 35 && (j == 2 || j == 3)) || ((i==36) && (j==3)))
				continue;
			posX = i * 100;
			posY = 910 - j * 100;
			MakeTile(posX, posY);
		}
	}
	
	/*떨어지는 블럭*/
	for (int i = 38; i < 38 + 2; i++)
	{
		for (int j = 0; j < 15; j++)
		{
			if (i == 38 && j == 0)
				continue;
			posX = i * 100;
			posY = (910 - 5 * 100) + j*100;
			MakeTile(posX, posY);
		}
	}

}

void GameSystem::Update()
{
	//float speed = 0;
	//if (inputManager.keyBuffer[VK_LEFT] == 1)
	//{
	//	//speed = 10 * 1;
	//	for (int i = 0; i < tiles.size(); i++)
	//	{
	//		tiles[i]->setPos(tiles[i]->getPos().x + speed, tiles[i]->getPos().y);
	//	}
	//}
	//else if (inputManager.keyBuffer[VK_RIGHT] == 1)
	//{
	//	//speed = 10 * -1;
	//	for (int i = 0; i < tiles.size(); i++)
	//	{
	//		tiles[i]->setPos(tiles[i]->getPos().x - speed, tiles[i]->getPos().y);
	//	}
	//}
	//else if (inputManager.keyBuffer[VK_UP] == 1)
	//{
	//	for (int i = 0; i < tiles.size(); i++)
	//	{
	//		tiles[i]->setPos(tiles[i]->getPos().x, tiles[i]->getPos().y + speed);
	//	}
	//}
	//else if (inputManager.keyBuffer[VK_DOWN] == 1)
	//{
	//	for (int i = 0; i < tiles.size(); i++)
	//	{
	//		tiles[i]->setPos(tiles[i]->getPos().x , tiles[i]->getPos().y - speed);
	//	}
	//}
	float row_speed = 0;
	float column_speed = 0;
	float speed = 20;
	for (int i = 0; i < tiles.size(); i++)
	{
		if (inputManager.keyBuffer[VK_LEFT] == 1)
			row_speed = speed * 1;
		else if (inputManager.keyBuffer[VK_RIGHT] == 1)
			row_speed = speed * -1;
		else if (inputManager.keyBuffer[VK_UP] == 1)
			column_speed = speed * 1;
		else if (inputManager.keyBuffer[VK_DOWN] == 1)
			column_speed = speed * -1;

		tiles[i]->setPos(tiles[i]->getPos().x + row_speed , tiles[i]->getPos().y + column_speed);
	}
	player->setPos(player->getPos().x + row_speed, player->getPos().y + column_speed);



	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Update();
	}
}

void GameSystem::Render()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Render();
	}
}