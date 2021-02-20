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

/* Texture ID */
// Background
#define TEX_TITLE_PAGE_BACKGROUND 1000
#define TEX_FIRST_GAME_PAGE_BACKGROUND 1100

// Object
#define TEX_CLOUD_A 2000
#define TEX_CLOUD_A_BAD 2001
#define TEX_CLOUD_B 2002
#define TEX_CLOUD_B_BAD 2003
#define TEX_ENEMY_A 2004
#define TEX_ENEMY_B 2005
#define TEX_ENEMY_C 2006
#define TEX_ENEMY_D 2007
#define TEX_PLAYER 2008
#define TEX_BRICK 2009
#define TEX_GOLD_A 2010
#define TEX_GOLD_B 2011
#define TEX_GOLD_C 2012
#define TEX_GOLD_D 2013
#define TEX_GOLD_E 2014
#define TEX_GOLD_F 2015
#define TEX_GOLD_G 2016
#define TEX_DAMAGE_TILE 2017

// UI
#define TEX_TITLE_PAGE_TITLE 3000
#define TEX_START_BUTTON_NOMAL 3001
#define TEX_START_BUTTON_BORD 3002
#define TEX_EXIT_BUTTON_NOMAL 3003
#define TEX_EXIT_BUTTON_BORD 3004
#define TEX_GAME_OVER_A 3005
#define TEX_GAME_OVER_B 3006

// Character

// Other



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










