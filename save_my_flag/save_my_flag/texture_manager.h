#pragma once
#include <d3dx9.h>
#include <vector>
using namespace std;

class TextureElement
{
public:
	int id;
	LPDIRECT3DTEXTURE9* texture;
};

class TextureManager
{
public:
	vector<TextureElement> elements;

	void LoadTexture(const char* name, int id);
	LPDIRECT3DTEXTURE9* getTexture(int id);

};