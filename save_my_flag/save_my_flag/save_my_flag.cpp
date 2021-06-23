// save_my_flag.cpp : 애플리케이션에 대한 진입점을 정의합니다.
// 


#include "framework.h"
#include "save_my_flag.h"

#include <Windows.h>
#include <mmsystem.h>
#include <d3dx9.h>
#pragma warning( disable : 4996 ) // disable deprecated warning 
#include <strsafe.h>
#pragma warning( default : 4996 )
#include "global.h"

#define MAX_LOADSTRING 100

// 전역 변수:
HINSTANCE hInst;                                // 현재 인스턴스입니다.
WCHAR szTitle[MAX_LOADSTRING];                  // 제목 표시줄 텍스트입니다.
WCHAR szWindowClass[MAX_LOADSTRING];            // 기본 창 클래스 이름입니다.


// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM                MyRegisterClass(HINSTANCE hInstance);
BOOL                InitInstance(HINSTANCE, int);
LRESULT CALLBACK    WndProc(HWND, UINT, WPARAM, LPARAM);


/* global */
// basic
HWND hWnd;
LPDIRECT3D9         g_pD3D = NULL;
LPDIRECT3DDEVICE9   g_pd3dDevice = NULL;

// Manager
TextureManager textureManager;
InputManager inputManager;
PageManager pageManager;
DataManager dataManager;
GameSystem gameSystem;
CSoundManager soundManager;


// Other
float deltaTime = 0.3f;
DWORD prevTime;
Cheat cheat;
PlayerInfo ranking[7];


HRESULT InitD3D(HWND hWnd)
{
    // Create the D3D object.
    if (NULL == (g_pD3D = Direct3DCreate9(D3D_SDK_VERSION)))
        return E_FAIL;

    // Set up the structure used to create the D3DDevice. Since we are now
    // using more complex geometry, we will create a device with a zbuffer.
    D3DPRESENT_PARAMETERS d3dpp;
    ZeroMemory(&d3dpp, sizeof(d3dpp));
    /*d3dpp.Windowed = TRUE;
    d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
    d3dpp.BackBufferFormat = D3DFMT_UNKNOWN;
    d3dpp.EnableAutoDepthStencil = TRUE;
    d3dpp.AutoDepthStencilFormat = D3DFMT_D16;*/


	d3dpp.Windowed = false;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.BackBufferFormat = D3DFMT_A8R8G8B8;
	d3dpp.BackBufferWidth = WINDOW_WIDTH;
	d3dpp.BackBufferHeight = WINDOW_HEIGHT;

    // Create the D3DDevice
    if (FAILED(g_pD3D->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd,
        D3DCREATE_SOFTWARE_VERTEXPROCESSING,
        &d3dpp, &g_pd3dDevice)))
    {
        return E_FAIL;
    }

    return S_OK;
}

void InitMyStuff()
{
    //background
    textureManager.LoadTexture(L"source/image/background/title_page.png", TEX_TITLE_PAGE_BACKGROUND);
    textureManager.LoadTexture(L"source/image/background/first_game_page.png", TEX_FIRST_GAME_PAGE_BACKGROUND);
    textureManager.LoadTexture(L"source/image/background/rank_page.png", TEX_RANK_PAGE);
    
	// object
	textureManager.LoadTexture(L"source/image/object/cloud_a.png", TEX_CLOUD_A);
	textureManager.LoadTexture(L"source/image/object/cloud_a_bad.png", TEX_CLOUD_A_BAD);
	textureManager.LoadTexture(L"source/image/object/cloud_b.png", TEX_CLOUD_B);
	textureManager.LoadTexture(L"source/image/object/cloud_b_bad.png", TEX_CLOUD_B_BAD);
	textureManager.LoadTexture(L"source/image/object/enemy/enemy_a.png", TEX_ENEMY_A_1);
	textureManager.LoadTexture(L"source/image/object/enemy/enemy_b.png", TEX_ENEMY_A_2);
	textureManager.LoadTexture(L"source/image/object/enemy/enemy_c.png", TEX_ENEMY_A_3);
    textureManager.LoadTexture(L"source/image/object/enemy/enemy_d.png", TEX_ENEMY_A_4);
    textureManager.LoadTexture(L"source/image/object/flag.png", TEX_FLAG);

	textureManager.LoadTexture(L"source/image/object/tile/brick_nomal.png", TEX_BRICK);
	textureManager.LoadTexture(L"source/image/object/tile/damage_tile.png", TEX_DAMAGE_TILE);

	textureManager.LoadTexture(L"source/image/object/gold/gold_a.png", TEX_GOLD_A);
	textureManager.LoadTexture(L"source/image/object/gold/gold_b.png", TEX_GOLD_B);
	textureManager.LoadTexture(L"source/image/object/gold/gold_c.png", TEX_GOLD_C);
	textureManager.LoadTexture(L"source/image/object/gold/gold_d.png", TEX_GOLD_D);
	textureManager.LoadTexture(L"source/image/object/gold/gold_e.png", TEX_GOLD_E);
	textureManager.LoadTexture(L"source/image/object/gold/gold_f.png", TEX_GOLD_F);
	textureManager.LoadTexture(L"source/image/object/gold/gold_g.png", TEX_GOLD_G);

    //ui
    textureManager.LoadTexture(L"source/image/ui/title_page/title.png", TEX_TITLE_PAGE_TITLE);
	textureManager.LoadTexture(L"source/image/ui/title_page/start_button_nomal.png", TEX_START_BUTTON_NOMAL);
	textureManager.LoadTexture(L"source/image/ui/title_page/start_button_mouseover.png", TEX_START_BUTTON_BORD);
	textureManager.LoadTexture(L"source/image/ui/title_page/exit_button_nomal.png", TEX_EXIT_BUTTON_NOMAL);
	textureManager.LoadTexture(L"source/image/ui/title_page/exit_button_mouseover.png", TEX_EXIT_BUTTON_BORD);
    textureManager.LoadTexture(L"source/image/ui/title_page/manual_button_nomal.png", TEX_MANUAL_BUTTON_NOMAL);
    textureManager.LoadTexture(L"source/image/ui/title_page/manual_button_mouseover.png", TEX_MANUAL_BUTTON_BORD);
    textureManager.LoadTexture(L"source/image/ui/title_page/ranking_button_nomal.png", TEX_RANKING_BUTTON_NOMAL);
    textureManager.LoadTexture(L"source/image/ui/title_page/ranking_button_mouseover.png", TEX_RANKING_BUTTON_BORD);
	textureManager.LoadTexture(L"source/image/ui/popup/game_over_A.png", TEX_GAME_OVER_A);
    textureManager.LoadTexture(L"source/image/ui/popup/game_over_B.png", TEX_GAME_OVER_B);
    textureManager.LoadTexture(L"source/image/ui/popup/game_clear.png", TEX_GAME_CLEAR);
	textureManager.LoadTexture(L"source/image/ui/popup/X.png", TEX_X);
	textureManager.LoadTexture(L"source/image/ui/return_button_a.png", TEX_RETURN_BUTTON_NOMAL);
	textureManager.LoadTexture(L"source/image/ui/return_button_B.png", TEX_RETURN_BUTTON_MOUSEOVER);
	textureManager.LoadTexture(L"source/image/ui/main_button_a.png", TEX_MAIN_BUTTON_NOMAL);
    textureManager.LoadTexture(L"source/image/ui/main_button_B.png", TEX_MAIN_BUTTON_MOUSEOVER);

    textureManager.LoadTexture(L"source/image/ui/score.png", TEX_SCORE);
    textureManager.LoadTexture(L"source/image/ui/name.png", TEX_NAME);

    textureManager.LoadTexture(L"source/image/ui/back_button_border.png", TEX_BACK_BORDER);
    textureManager.LoadTexture(L"source/image/ui/back_button_normal.png", TEX_BACK_NORMAL);

    
	// character
	textureManager.LoadTexture(L"source/image/character/player.png", TEX_PLAYER);
	textureManager.LoadTexture(L"source/image/character/player_a.png", TEX_PLAYER_A);
	textureManager.LoadTexture(L"source/image/character/player_b.png", TEX_PLAYER_B);
	textureManager.LoadTexture(L"source/image/character/player_c.png", TEX_PLAYER_C);
	textureManager.LoadTexture(L"source/image/character/player_d.png", TEX_PLAYER_D);
	textureManager.LoadTexture(L"source/image/character/player_e.png", TEX_PLAYER_E);
	textureManager.LoadTexture(L"source/image/character/player_f.png", TEX_PLAYER_F);
    
	//pageManager.CreateMapEditPage();
    pageManager.CreateTitlePage();
    prevTime = GetTickCount();

    for (int i = 0; i < 7; ++i)
    {
        strcpy_s<128>(ranking[i].playerName, "player");
        ranking[i].playerScore = 0;
    }
}


void initSound()
{
    soundManager.Initialize(hWnd, DSSCL_NORMAL);

    {
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/title.wav");
        soundManager.Create(&soundManager.BGMTitleStage, fileName);
    }
    {
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/firstgame.wav");
        soundManager.Create(&soundManager.BGMFirstStage, fileName);
    }
    {
        //
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/rank.wav");  
        soundManager.Create(&soundManager.BGMRankStage, fileName);
    }
    {
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/popup.wav");
        soundManager.Create(&soundManager.BGMPopup, fileName);
    }
    {
        //
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/Game Over.wav");
        soundManager.Create(&soundManager.sndDie, fileName);
    }
    {
        //
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/gameclear.wav");
        soundManager.Create(&soundManager.sndClear, fileName);
    }
    {
        //
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/jump.wav");
        soundManager.Create(&soundManager.sndJump, fileName);
    }
    {
        //
        WCHAR fileName[MAX_PATH];
        swprintf_s<MAX_PATH>(fileName, L"source/sound/coin.wav");
        soundManager.Create(&soundManager.sndCoin, fileName);
    }

}

void Render()
{
    
    g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET,
        D3DCOLOR_XRGB(0, 0, 255), 1.0f, 0);
   
    if (SUCCEEDED(g_pd3dDevice->BeginScene()))
    {
        pageManager.Render();
        g_pd3dDevice->EndScene();
    }

  
    g_pd3dDevice->Present(NULL, NULL, NULL, NULL);
}

void Update()
{

    DWORD cur = GetTickCount();
    DWORD diff = cur - prevTime;
    deltaTime = diff / 1000.0f;
    if (deltaTime > 0.016f)
    {
        deltaTime = 0.016f;
    }
    prevTime = cur;

    if (inputManager.prevKeyBuffer[VK_ESCAPE] == 1 && inputManager.keyBuffer[VK_ESCAPE] == 0)
    {
       PostQuitMessage(0);
      
    }

    pageManager.Update();
    cheat.Update();
    inputManager.Update();
}

void GameLoop()
{
    Render();
    Update();
}

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPWSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // TODO: 여기에 코드를 입력합니다.

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_SAVEMYFLAG, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    // 애플리케이션 초기화를 수행합니다:
    if (!InitInstance (hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_SAVEMYFLAG));

    MSG msg;
    ZeroMemory(&msg, sizeof(msg));
    while (msg.message != WM_QUIT)
    {
        if (PeekMessage(&msg, NULL, 0U, 0U, PM_REMOVE))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        else
        {
            GameLoop();
        }

    }
    return (int) msg.wParam;
}


ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);

    wcex.style          = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc    = WndProc;
    wcex.cbClsExtra     = 0;
    wcex.cbWndExtra     = 0;
    wcex.hInstance      = hInstance;
    wcex.hIcon          = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_SAVEMYFLAG));
    wcex.hCursor        = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW+1);
    wcex.lpszMenuName   = nullptr;
    wcex.lpszClassName  = szWindowClass;
    wcex.hIconSm        = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}


BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   hInst = hInstance; // 인스턴스 핸들을 전역 변수에 저장합니다.

   hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, WINDOW_WIDTH, WINDOW_HEIGHT, nullptr, nullptr, hInstance, nullptr);

   if (!hWnd)
   {
      return FALSE;
   }

   InitD3D(hWnd);
   initSound();
   InitMyStuff();
   
   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_KEYUP:
        inputManager.keyBuffer[wParam] = 0;
        break;
    case WM_KEYDOWN:
        inputManager.keyBuffer[wParam] = 1;
        break;
    case WM_LBUTTONDOWN:
        inputManager.keyBuffer[VK_LBUTTON] = 1;
        break;
    case WM_LBUTTONUP:
        inputManager.keyBuffer[VK_LBUTTON] = 0;
        break;
    case WM_DESTROY:
        PostQuitMessage(0);
        break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

