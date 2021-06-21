#pragma once
#include <d3dx9.h>
#include <vector>
using namespace std;


class GameOver
{
public:

	int a = 0;
	GameOver();
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