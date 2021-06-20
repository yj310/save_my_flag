#include "player.h"
#include "global.h"
#include <ctime>

#define PLAYER_WIDTH 100
#define PLAYER_HEIGHT 100
#define PLAYER_BOTTOM 860

Player::Player()
{
	posX = 250;
	jumpStartPosY = START_BOTTOM-10;
	bottomY = START_BOTTOM;
	posY = jumpStartPosY;
	radious = 50;
	isJump = false;
	isDead = false;
	speed = 10;
	gravity = GRAVITY;	//중력가속도

	jumpTime = 0.0f;	//점프 이후 경과시간
	jumpPower = 40.0f;	//점프력
	jumpHeight = 0;
	//
	printX = posX;
	printY = posY;

	srand((unsigned int)time(NULL));
	randCharacter = TEX_PLAYER_A + rand() % 6;

	isTouch_top = true;
	isTouch_bottom = false;
	isTouch_right = true;
	isTouch_left = true;

}

void Player::Update()
{
	Gravity();

	//player motion
	if (inputManager.keyBuffer['W'] == 1 && !isJump && !isTouch_top && isTouch_bottom)
	{
		isTouch_bottom = false;
		isJump = true;
		jumpTime = 1.f;
		jumpStartPosY = posY;
	}
	if (inputManager.keyBuffer['A'] == 1 && !isTouch_left)
	{
		posX -= speed;
	}
	if (inputManager.keyBuffer['D'] == 1 && !isTouch_right)
	{
		posX += speed;
	}
	/*if (inputManager.keyBuffer['S'] == 1 && !isTouch_bottom)
	{
		posY += speed;
	}*/

	//jump
	if (isJump)
	{
		posY = jumpStartPosY + jumpHeight;
		Jump();
	}


}

void Player::Render()
{
	TextureElement* element;
	RECT rc;
	D3DXVECTOR3 pos;
	D3DXVECTOR3 cen;

	element = textureManager.getTexture(randCharacter);

	element->sprite->Begin(D3DXSPRITE_ALPHABLEND);

	rc.left = 0;
	rc.top = 0;
	rc.right = PLAYER_WIDTH;
	rc.bottom = PLAYER_HEIGHT;

	cen = { PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2, 0 };
	pos = { printX, printY, 0 };

	element->sprite->Draw(element->texture, &rc, &cen, &pos, D3DCOLOR_ARGB(255, 255, 255, 255));

	element->sprite->End();
}

void Player::Gravity()
{
	//posY += 15;
	if (!isTouch_bottom) {
		posY += gravity;
	}
		
	//accumulatedGravityPower = deltaTime * gravity;
	//posY += accumulatedGravityPower;
}

void Player::Jump()
{
	jumpHeight = jumpTime * jumpTime - jumpPower * jumpTime;
	

	jumpTime += 1.0f;

	if (jumpTime >= jumpPower)
	{
		jumpTime = 0.f;
		jumpHeight = 0.f;

		isJump = false;
	}
}

D3DXVECTOR2 Player::getCenter()
{
	return { PLAYER_WIDTH / 2, PLAYER_HEIGHT / 2 };
}

float Player::getSpeed()
{
	return speed;
}

void Player::setPos(float x, float y)
{
	posX = x;
	posY = y;

}

D3DXVECTOR2 Player::getPos()
{
	return { posX, posY };
}

D3DXVECTOR2 Player::getSize()
{
	return { PLAYER_WIDTH, PLAYER_HEIGHT };
}

int  Player::getRadious()
{
	return radious;
}

bool Player::getIsDead()
{
	return isDead;
}


void Player::setPrintPos()
{

	// printX
	if (posX <= WINDOW_WIDTH / 2)
	{
		printX = posX;
	}
	else
	{
		if (posX > FINISH_TILE_RIGHT - (WINDOW_WIDTH / 2))
		{
			printX = (WINDOW_WIDTH / 2) + ((WINDOW_WIDTH / 2) - (FINISH_TILE_RIGHT - posX));
		}
		else
		{
			printX = posX - (posX - (WINDOW_WIDTH / 2));
		}
	}


	/*if (printY <WINDOW_HEIGHT/2 && isTouch_bottom) {
		bottomY = 100;
		isTouch_bottom = false;
	}
	else {
		bottomY = 0;
		
	}*/

	printY = posY;

	//// printY
	if (posY >= WINDOW_HEIGHT / 2 - 100 && posY <= START_BOTTOM)
	{
		printY = posY - (START_BOTTOM - ((WINDOW_HEIGHT / 2) + 300)) + 50;
	}
	else if (posY < WINDOW_HEIGHT / 2 - 100)
	{
		printY = WINDOW_HEIGHT / 2 - 100;
	}
	else if (posY > START_BOTTOM)
	{
		printY = posY;
		/*if (posY + (WINDOW_HEIGHT - START_BOTTOM) > FINISH_TILE_BOTTOM) {
			printY = START_BOTTOM + ((WINDOW_HEIGHT - START_BOTTOM) - (FINISH_TILE_BOTTOM - posY));
		}
		else
		{
			printY = START_BOTTOM;
		}*/
	}
	//printY = posY;
}