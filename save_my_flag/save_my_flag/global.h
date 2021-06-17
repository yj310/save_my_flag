#pragma once

#include <d3dx9.h>
#include <d3dx9core.h>

#include <vector>

// Managers
#include "texture_manager.h"
#include "input_manager.h"
#include "page_manager.h"
#include "data_manager.h"
#include "game_system.h"

#include "cheat.h"



// window size
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

// page
#define TEX_FADING 0
#define TITLE_PAGE 1
#define FIRST_GAME_PAGE 2

// tile
#define NOMAL_BRICK 0
#define DAMAGE_TILE 1
#define DROP_BRICK 2

// map
#define START_BOTTOM 910
#define FINISH_TILE_RIGHT 10700
#define FINISH_TILE_BOTTOM START_BOTTOM + 1000

#define GRAVITY 20.5

/* Texture ID */
// Background
#define TEX_TITLE_PAGE_BACKGROUND 1000
#define TEX_FIRST_GAME_PAGE_BACKGROUND 1100


// Object
#define TEX_CLOUD_A					2000
#define TEX_CLOUD_A_BAD				2001
#define TEX_CLOUD_B					2002
#define TEX_CLOUD_B_BAD				2003

#define TEX_ENEMY_A_1				2010
#define TEX_ENEMY_A_2				2011
#define TEX_ENEMY_A_3				2012
#define TEX_ENEMY_A_4				2013

#define TEX_GOLD_A					2030
#define TEX_GOLD_B					2031
#define TEX_GOLD_C					2032
#define TEX_GOLD_D					2033
#define TEX_GOLD_E					2034
#define TEX_GOLD_F					2035
#define TEX_GOLD_G					2036

#define TEX_BRICK					2050
#define TEX_DAMAGE_TILE				2051


// UI
#define TEX_TITLE_PAGE_TITLE		3000
#define TEX_START_BUTTON_NOMAL		3001
#define TEX_START_BUTTON_BORD		3002
#define TEX_EXIT_BUTTON_NOMAL		3003
#define TEX_EXIT_BUTTON_BORD		3004
#define TEX_GAME_OVER_A				3005
#define TEX_GAME_OVER_B				3006
#define TEX_X						3007
#define TEX_RETURN_BUTTON_NOMAL		3008
#define TEX_RETURN_BUTTON_MOUSEOVER	3009
#define TEX_MAIN_BUTTON_NOMAL		3010
#define TEX_MAIN_BUTTON_MOUSEOVER	3011
#define TEX_MANUAL_BUTTON_NOMAL		3020
#define TEX_MANUAL_BUTTON_BORD		3021
#define TEX_RANKING_BUTTON_NOMAL	3022
#define TEX_RANKING_BUTTON_BORD		3023


// Character
#define TEX_PLAYER					4000
#define TEX_PLAYER_A				4001
#define TEX_PLAYER_B				4002
#define TEX_PLAYER_C				4003
#define TEX_PLAYER_D				4004
#define TEX_PLAYER_E				4005
#define TEX_PLAYER_F				4006


// Other
extern float deltaTime;

/* global */
// basic
extern LPDIRECT3D9 g_pD3D;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;


// Managers
extern TextureManager textureManager;
extern InputManager inputManager;
extern PageManager pageManager;
extern DataManager dataManager;
extern DataManager dataManager;
extern GameSystem gameSystem;

// Other
extern HWND hWnd;
extern float deltaTime;
extern Cheat cheat;










