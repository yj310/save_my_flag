#pragma once

#include <d3dx9.h>
#include <d3dx9core.h>

#include <vector>

// Managers
#include "texture_manager.h"
#include "input_manager.h"
#include "page_manager.h"
#include "data_manager.h"





// window size
#define WINDOW_WIDTH 1920
#define WINDOW_HEIGHT 1080

// page
#define TEX_FADING 0
#define TITLE_PAGE 1
#define FIRST_GAME_PAGE 1

/* Texture ID */
// Background
#define TEX_TITLE_PAGE_BACKGROUND 1000

// Object
#define TEX_TITLE_PAGE_TITLE 2000

// UI
#define TEX_START_BUTTON_NOMAL 3000
#define TEX_START_BUTTON_BORD 3001
#define TEX_EXIT_BUTTON_NOMAL 3002
#define TEX_EXIT_BUTTON_BORD 3003

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


// Other
extern HWND hWnd;
extern float deltaTime;










