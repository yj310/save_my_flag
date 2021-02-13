#pragma once

#include <d3dx9.h>
#include <vector>

using namespace std;

class TextureElement
{
public:
	int id;
	LPDIRECT3DTEXTURE9* tex;
};

class TextureManager
{
public:
	vector<TextureElement> elements;

	void LoadTexture(const char* filename, int id);
	LPDIRECT3DTEXTURE9* GetTexture(int id);

protected:
private:

};
