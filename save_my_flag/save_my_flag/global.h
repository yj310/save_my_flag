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
#define TITLE_PAGE 0

/* Texture ID */
// Background
#define TEX_TITLE_PAGE_BACKGROUND 1000

// Object

// UI
#define TEX_START_BUTTON_NOMAL 2000
#define TEX_START_BUTTON_BORD 2001

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
extern HWND MyhWnd;
extern float deltaTime;










