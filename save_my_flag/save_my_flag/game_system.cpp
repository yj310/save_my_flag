#include "game_system.h"
#include "global.h"
#include "player.h"
#include "tile.h"
#include "brick_normal.h"
#include "brick_drop.h"
#include "math_util.h"
#include "damage_tile.h"

#define START_BOTTOM 910

GameSystem::GameSystem()
{
	player = new Player();
	gameOverPage = new GameOver();
	group_number = -1;
}

void GameSystem::CreateMap()
{
	GenerateTiles();
}

void GameSystem::MakeNomalBrickTile(float x, float y)
{
	Tile* tile = new BrickNormal(x, y);
	tiles.push_back(tile);
}

void GameSystem::MakeDropBrickTile(float x, float y, int group)
{
	Tile* tile = new BrickDrop(x, y, group);
	tiles.push_back(tile);
}

void GameSystem::MakeDamageTile(float x, float y)
{
	Tile* tile = new DamageTile(x, y);
	tiles.push_back(tile);
}

void GameSystem::GenerateTiles()
{
	float posX, posY;


	
	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeNomalBrickTile(posX, posY);
		}
	}


	MakeNomalBrickTile(500, START_BOTTOM - 100);
	MakeNomalBrickTile(15 * 100, START_BOTTOM - 100 * 1);

	/*떨어지는 블럭*/
	for (int i = 16; i < 19; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeDropBrickTile(posX, posY, 0);
		}
	}

	for (int i = 19; i < 19 + 19; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeNomalBrickTile(posX, posY);
		}
	}
	for (int i = 35; i < 35 + 3; i++)
	{
		for (int j = 1; j < 1 + 3; j++)
		{
			if ((i == 35 && (j == 2 || j == 3)) || ((i == 36) && (j == 3)))
				continue;
			posX = i * 100;
			posY = START_BOTTOM - j * 100;
			MakeNomalBrickTile(posX, posY);
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
			posY = (START_BOTTOM - 5 * 100) + j * 100;
			MakeDropBrickTile(posX, posY, 1);
		}
	}

	for (int i = 40; i < 40 + 3; i++)
	{
		for (int j = 0; j < 18; j++)
		{
			if ((i == 40 && (j == 0 || j == 1)) || ((i == 41) && (j == 0)))
				continue;
			posX = i * 100;
			posY = (START_BOTTOM - 8 * 100) + j * 100;
			MakeNomalBrickTile(posX, posY);
		}
	}

	for (int i = 46; i < 46 + 28; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeNomalBrickTile(posX, posY);
		}
	}
	MakeNomalBrickTile(45 * 100, START_BOTTOM + 100 * 3);
	MakeNomalBrickTile(68 * 100, START_BOTTOM - 100 * 1);

	/*떨어지는 블럭*/
	for (int i = 74; i < 74 + 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeDropBrickTile(posX, posY, 2);
		}
	}


	// damage tile
	for (int i = 0; i < 100; i++)
	{
		MakeDamageTile(i * 100, START_BOTTOM + 1000);
	}
	for (int i = 0; i < 30; i++)
	{
		MakeDamageTile(-100, START_BOTTOM - 1900 + i * 100);
	}

}

void GameSystem::Update()
{


	//map <- ->
	float row_speed = 0;
	float column_speed = 0;
	float speed = 20;
	for (int i = 0; i < tiles.size(); i++)
	{
		if (inputManager.keyBuffer[VK_LEFT] == 1)
			row_speed = speed * 1;
		if (inputManager.keyBuffer[VK_RIGHT] == 1)
			row_speed = speed * -1;
		if (inputManager.keyBuffer[VK_UP] == 1)
			column_speed = speed * 1;
		if (inputManager.keyBuffer[VK_DOWN] == 1)
			column_speed = speed * -1;

		tiles[i]->setPos(tiles[i]->getPos().x + row_speed, tiles[i]->getPos().y + column_speed);
	}
	player->setPos(player->getPos().x + row_speed, player->getPos().y + column_speed);






	if (!player->isDead)
	{
		player->Update();


		for (int i = 0; i < tiles.size(); i++)
		{
			// 장외 처리
			if (tiles[i]->getTileType() == DAMAGE_TILE)
			{
				if (isCircleVsBoxCollided(player->getPos().x, player->getPos().y, player->getRadious(),
					tiles[i]->getPos().x, tiles[i]->getPos().y, tiles[i]->getSize().x, tiles[i]->getSize().y))
				{
					player->isDead = true;
				}
			}

			//충돌처리
			if (isCircleVsBoxCollided(player->getPos().x, player->getPos().y, player->getRadious(),
				tiles[i]->getPos().x, tiles[i]->getPos().y, tiles[i]->getSize().x, tiles[i]->getSize().y))
			{

				if (tiles[i]->getTileType() == DROP_BRICK)
				{
					group_number = tiles[i]->group;
				}
				/*player->state = 0;
				player->isDown = false;*/
			}
			else
			{
				player->isDown = true;
				player->state = 255;
			}



			int playerX = player->getPos().x;
			int playerY = player->getPos().y;
			int playerRadius = player->getRadious();
			int tileX = tiles[i]->getPos().x;
			int tileY = tiles[i]->getPos().y;
			int tileWidth = tiles[i]->getSize().x;
			int tileHeight = tiles[i]->getSize().y;

			if (playerX - playerRadius < tileX + tileWidth
				&& playerX + playerRadius > tileX)
			{

				if (playerY - playerRadius  < tileY + tileHeight
					&& playerY + playerRadius > tileY + tileHeight)
				{
					player->setPos(playerX, tileY + tileHeight + playerRadius);
					player->isJump = false;
				}
				if (playerY - playerRadius  < tileY
					&& playerY + playerRadius > tileY)
				{
					player->setPos(playerX, tileY - playerRadius);
					player->isJump = false;
				}
			}

			playerX = player->getPos().x;
			playerY = player->getPos().y;
			if (playerY - playerRadius < tileY + tileHeight
				&& playerY + playerRadius > tileY)
			{
				if (playerX - playerRadius  < tileX + tileWidth
					&& playerX + playerRadius > tileX + tileWidth)
				{
					player->setPos(tileX + tileWidth + playerRadius, playerY);
					player->isJump = false;
				}
				else if (playerX - playerRadius  < tileX
					&& playerX + playerRadius > tileX)
				{
					player->setPos(tileX - playerRadius, playerY);
					player->isJump = false;
				}
			}




		}

		for (int i = 0; i < tiles.size(); i++)
		{
			if (tiles[i]->group == group_number)
			{
				tiles[i]->posY += 100;
			}
			tiles[i]->Update();
		}
	}
	else
	{
		gameOverPage->Update();
	}

}

void GameSystem::Render()
{
	for (int i = 0; i < tiles.size(); i++)
	{
		player->Render();
		tiles[i]->Render();
	}

	if (player->isDead)
	{
		gameOverPage->Render();
	}
}

void GameSystem::deleteData()
{
	delete player;
	player = new Player();
	delete gameOverPage;
	gameOverPage = new GameOver();
	group_number = -1;
	int size = tiles.size();
	for (int i = 0; i < size; i++)
	{
		tiles.pop_back();
	}
}