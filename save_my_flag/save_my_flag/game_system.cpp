﻿#include "game_system.h"
#include "global.h"
#include "player.h"
#include "tile.h"
#include "brick_normal.h"
#include "brick_drop.h"
#include "brick_hidden.h"
#include "math_util.h"
#include "damage_tile.h"
#include "enemy_a.h"
#include "cloud_a.h"
#include "flag.h"




GameSystem::GameSystem()
{
	player = new Player();
	
	group_number = -1;
}

void GameSystem::CreateMap()
{
	GenerateTiles();
	GenerateEnemys();
	GenerateClouds();
	GenerateCoin();

	flag = new Flag(80 * 100, START_BOTTOM - 300+10);
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

void GameSystem::MakeHiddenTile(float x, float y)
{
	Tile* tile = new BrickHidden(x, y);
	tiles.push_back(tile);
}

void GameSystem::MakeEnemyA(float x, float y, float direction)
{
	Enemy* enemy = new EnemyA(x, y, direction);
	enemys.push_back(enemy);
}

void GameSystem::MakeCloud(float x, float y, int state, int type)
{
	Cloud* cloud = new CloudA(x, y, state, type);
	clouds.push_back(cloud);
}

void GameSystem::MakeCoin(float x, float y)
{
	Gold* coin = new Gold(x, y);
	coins.push_back(coin);
}


void GameSystem::GenerateTiles()
{
	float posX, posY;


	/* Damage Tile */
	for (int i = 0; i < 300; i++)
	{
		MakeDamageTile(i * 100, FINISH_TILE_BOTTOM);
	}
	for (int i = 0; i < 30; i++)
	{
		MakeDamageTile(-100, START_BOTTOM - 1900 + i * 100);
	}

	for (int i = 0; i < 16; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeNomalBrickTile(posX, posY);
		}
	}

	for (int i = 5; i < 5 + 2; i++)
	{
		posX = i * 100;
		posY = START_BOTTOM - 2 * 100;
		MakeNomalBrickTile(posX, posY);
	}

	MakeNomalBrickTile(15 * 100, START_BOTTOM - 100 * 1);

	/* Drop Brick Tile */
	for (int i = 16; i < 21; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeDropBrickTile(posX, posY, 0);
		}
	}

	for (int i = 21; i < 21 + 17; i++)
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

	/* Drop Brick Tile */
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

	MakeNomalBrickTile(53 * 100, START_BOTTOM - 100 * 1);
	MakeNomalBrickTile(68 * 100, START_BOTTOM - 100 * 1);


	//hidden
	MakeHiddenTile(59 * 100, START_BOTTOM - 400 * 1);
	MakeHiddenTile(60 * 100, START_BOTTOM - 400 * 1);
	/*MakeHiddenTile(66 * 100, START_BOTTOM - 400 * 1);*/

	

	/* Drop Brick Tile */
	for (int i = 74; i < 74 + 4; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			posX = i * 100;
			posY = START_BOTTOM + j * 100;
			MakeDropBrickTile(posX, posY, 2);
		}
	}

	for (int i = 78; i < 100; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			/*if (((i == 83) || (i == 84) || (i == 85)) && ((j == 7) || (j == 8)))
				continue;*/
				posX = i * 100;
				posY = START_BOTTOM + j * 100;
				MakeNomalBrickTile(posX, posY);
		}
	}
	
}

void GameSystem::GenerateEnemys()
//53 * 100
{
	MakeEnemyA(8 * 100, START_BOTTOM - 50, -1);

	MakeEnemyA(55 * 100, START_BOTTOM - 50, -1);
	
	MakeEnemyA(65 * 100, START_BOTTOM - 50, -1);
	//MakeEnemyA(55 * 100, START_BOTTOM - 50, -1);

}

void GameSystem::GenerateCoin()
{
	MakeCoin(23 * 100, START_BOTTOM - 50);
	MakeCoin(60 * 100, START_BOTTOM - 500);
}

void GameSystem::GenerateClouds()
{
	MakeCloud(300, 30, normal, TEX_CLOUD_A);
	MakeCloud(2000, 80, normal, TEX_CLOUD_B);
	MakeCloud(3500, -200, down, TEX_CLOUD_A);
	MakeCloud(4900, 80, down, TEX_CLOUD_B);
	MakeCloud(88*100, 80, updown, TEX_CLOUD_A);
}


void GameSystem::Update()
{
	//map <- ->
	float row_speed = 0;
	float column_speed = 0;
	float speed = 20;
	/*if (inputManager.keyBuffer[VK_LEFT] == 1)
		row_speed = speed * 1;
	if (inputManager.keyBuffer[VK_RIGHT] == 1)
		row_speed = speed * -1;
	if (inputManager.keyBuffer[VK_UP] == 1)
		column_speed = speed * 1;
	if (inputManager.keyBuffer[VK_DOWN] == 1)
		column_speed = speed * -1;*/
	for (int i = 0; i < tiles.size(); i++)
	{	
		tiles[i]->setPos(tiles[i]->getPos().x + row_speed, tiles[i]->getPos().y + column_speed);
	}
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->setPos(enemys[i]->getPos().x + row_speed, enemys[i]->getPos().y + column_speed);
	}
	for (int i = 0; i < coins.size(); i++)
	{
		coins[i]->setPos(coins[i]->getPos().x + row_speed, coins[i]->getPos().y + column_speed);
	}
	for (int i = 0; i < clouds.size(); i++)
	{
		clouds[i]->setStartPosY(clouds[i]->getStartPosY() + column_speed);
		clouds[i]->setPos(clouds[i]->getPos().x + row_speed, clouds[i]->getPos().y + column_speed);
	}


	player->setPos(player->getPos().x + row_speed, player->getPos().y + column_speed);
	
	


	if (!player->isDead && !player->isClear)
	{
		flag->Update();

		player->Update();
		for (int i = 0; i < tiles.size(); i++)
		{
			if (tiles[i]->group == group_number)
			{
				tiles[i]->posY += 100;
			}
			tiles[i]->Update();
		}
		for (int i = 0; i < enemys.size(); i++)
		{
			enemys[i]->Update();
		}
		for (int i = 0; i < clouds.size(); i++)
		{	
			if (clouds[i]->getState() != normal)
			{
				if (player->getPos().x > clouds[i]->getPos().x)
				{
					clouds[i]->setIsStart(true);
				}
			}
			clouds[i]->Update();
		}
		for (int i = 0; i < coins.size(); i++)
		{
			coins[i]->Update();
		}


		player->isTouch_top = false;
		player->isTouch_bottom = false;
		player->isTouch_right = false;
		player->isTouch_left = false;


		for (int i = 0; i < tiles.size(); i++)
		{

			// Collision player and dropbrick
			if (isCircleVsBoxCollided(player->getPos().x, player->getPos().y, player->getRadious(),
				tiles[i]->getPos().x, tiles[i]->getPos().y, tiles[i]->getSize().x, tiles[i]->getSize().y))
			{

				if (tiles[i]->getTileType() == DROP_BRICK)
				{
					group_number = tiles[i]->group;			
				}

				if (tiles[i]->getTileType() == DAMAGE_TILE)
				{
					player->IsDead();
				}
				
				if (tiles[i]->getTileType() == HIDDEN_BRICK) {
					tiles[i]->isCollided = true;
				}
			}





			// Collision player and tiles
			int playerX = player->getPos().x;
			int playerY = player->getPos().y;
			int playerRadius = player->getRadious();
			int tileX = tiles[i]->getPos().x;
			int tileY = tiles[i]->getPos().y;
			int tileWidth = tiles[i]->getSize().x;
			int tileHeight = tiles[i]->getSize().y;

			if (playerX - playerRadius + 5 < tileX + tileWidth
				&& playerX + playerRadius - 5 > tileX)
			{
				if (playerY - playerRadius <= tileY + tileHeight
					&& playerY + playerRadius >= tileY + tileHeight)
				{
					player->isTouch_top = true;
					player->setPos(playerX, tileY + tileHeight + playerRadius);
					player->isJump = false;
				}
				if (playerY - playerRadius <= tileY
					&& playerY + playerRadius >= tileY)
				{
					player->isTouch_bottom = true;
					player->setPos(playerX, tileY - playerRadius);
					player->isJump = false;
				}

			}

			playerX = player->getPos().x;
			playerY = player->getPos().y;
			if (playerY - playerRadius < tileY + tileHeight
				&& playerY + playerRadius > tileY)
			{
				if (playerX - playerRadius <= tileX + tileWidth
					&& playerX + playerRadius >= tileX + tileWidth)
				{
					player->isTouch_left = true;
					player->setPos(tileX + tileWidth + playerRadius, playerY);
				}
				else if (playerX - playerRadius <= tileX
					&& playerX + playerRadius >= tileX)
				{
					player->isTouch_right = true;
					player->setPos(tileX - playerRadius, playerY);
				}
			}



			// Collision enemy and tile
			for (int j = 0; j < enemys.size(); j++)
			{
				int enemyX = enemys[j]->getPos().x;
				int enemyY = enemys[j]->getPos().y;
				int enemyRadius = enemys[j]->getRadious();

				if (enemyX - enemyRadius + 5 < tileX + tileWidth
					&& enemyX + enemyRadius - 5 > tileX)
				{
					if (enemyY - enemyRadius <= tileY + tileHeight
						&& enemyY + enemyRadius >= tileY + tileHeight)
					{
						enemys[j]->isTouch_top = true;
						enemys[j]->setPos(enemyX, tileY + tileHeight + enemyRadius);
					}
					if (enemyY - enemyRadius <= tileY
						&& enemyY + enemyRadius >= tileY)
					{
						enemys[j]->isTouch_bottom = true;
						enemys[j]->setPos(enemyX, tileY - enemyRadius);
					}

				}
				

				enemyX = enemys[j]->getPos().x;
				enemyY = enemys[j]->getPos().y;
				if (enemyY - enemyRadius < tileY + tileHeight
					&& enemyY + enemyRadius > tileY)
				{
					if (enemyX - enemyRadius <= tileX + tileWidth
						&& enemyX + enemyRadius >= tileX + tileWidth)
					{
						enemys[j]->direction = 1;
						if(enemys[j]->getState() == TEX_ENEMY_A_1)
							enemys[j]->state = TEX_ENEMY_A_3;
						else
							enemys[j]->state = TEX_ENEMY_A_4;
						enemys[j]->setPos(tileX + tileWidth + enemyRadius, enemyY);
					}
					else if (enemyX - enemyRadius <= tileX
						&& enemyX + enemyRadius >= tileX)
					{
						enemys[j]->direction = -1; 
						if (enemys[j]->getState() == TEX_ENEMY_A_3)
							enemys[j]->state = TEX_ENEMY_A_1;
						else
							enemys[j]->state = TEX_ENEMY_A_2;
						enemys[j]->setPos(tileX - enemyRadius, enemyY);
					}
				}
				
			}


		}

		for (int i = 0; i < enemys.size(); i++)
		{
			if (isCircleCollided(player->getPos().x, player->getPos().y, player->getRadious(),
				enemys[i]->getPos().x, enemys[i]->getPos().y, enemys[i]->getRadious()))
			{
				player->IsDead();
			}

		}

		for (int i = 0; i < coins.size(); i++)
		{
			if (!coins[i]->isTouch)
			{
				if (isCircleCollided(player->getPos().x, player->getPos().y, player->getRadious(),
					coins[i]->getPos().x, coins[i]->getPos().y, coins[i]->getRadious()))
				{
					coins[i]->isTouch = true;
					player->AddCoin();

					soundManager.sndCoin->Reset();
					soundManager.sndCoin->Play(0, 0, 2);
				}
			}
			
		}

		for (int i = 0; i < clouds.size(); i++)
		{
			if (clouds[i]->getState() != normal)
			{
				if (isCircleVsBoxCollided(player->getPos().x, player->getPos().y, player->getRadious(),
					clouds[i]->getPos().x, clouds[i]->getPos().y, clouds[i]->getSize().x, clouds[i]->getSize().y))
				{
					player->IsDead();
				}
			}
			
		}
		if (isCircleVsBoxCollided(player->getPos().x, player->getPos().y, player->getRadious(),
			flag->getPos().x, flag->getPos().y, flag->getSize().x, flag ->getSize().y))
		{
			player->isClear = true;
		}

		player->setPrintPos();

	}
	else if(player->isDead && !done)
	{
		soundManager.BGMFirstStage->Stop();
		soundManager.sndDie->Reset();
		soundManager.sndDie->Play(0, 0, 1);
		done = true;
	}
	else if (player->isClear && !done)
	{
		soundManager.BGMFirstStage->Stop();
		soundManager.sndClear->Reset();
		soundManager.sndClear->Play(0, 0, 1);
		done = true;
	}


	
}

void GameSystem::Render()
{
	
	flag->Render();
	player->Render();
	for (int i = 0; i < enemys.size(); i++)
	{
		enemys[i]->Render();
	}
	for (int i = 0; i < tiles.size(); i++)
	{
		tiles[i]->Render();
	}
	for (int i = 0; i < clouds.size(); i++)
	{
		clouds[i]->Render();
	}
	for (int i = 0; i < coins.size(); i++)
	{
		coins[i]->Render();
	}
	if (player->isDead)
	{
		//gameOverPage->Render();
	}

	
}

void GameSystem::deleteData()
{
	delete player;
	player = new Player();
	delete flag;
	flag = new Flag(80 * 100, START_BOTTOM - 300 + 10);
	//delete gameOverPage;
	//gameOverPage = new GameOver();
	int size = tiles.size();
	for (int i = 0; i < size; i++)
	{
		tiles.pop_back();
	}
	size = enemys.size();
	for (int i = 0; i < size; i++)
	{
		enemys.pop_back();
	}
	size = clouds.size();
	for (int i = 0; i < size; i++)
	{
		clouds.pop_back();
	}
	size = coins.size();
	for (int i = 0; i < size; i++)
	{
		coins.pop_back();
	}
	group_number = -1;
	done = false;
}

D3DXVECTOR2 GameSystem::getPrintPos(float x, float y)
{	
	return { x - (player->getPos().x - player->getPrintPos().x), y - (player->getPos().y - player->getPrintPos().y) };
}