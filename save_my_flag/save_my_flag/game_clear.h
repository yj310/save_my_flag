#pragma once
#include <d3dx9.h>
#include <vector>
using namespace std;


class GameClear
{
public:

	int a = 0;
	GameClear();
	void Update();
	void Render();

	int randPage;
	int enterTimer;
	int returnButtonState;
	int mainButtonState;
	vector<char> cname;

	ID3DXFont* font1;
	ID3DXFont* font2;

};