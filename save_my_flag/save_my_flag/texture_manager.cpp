
#include "texture_manager.h"
#include "global.h"

void TextureManager::LoadTexture(const char* name, int id)
{
	TextureElement element;
	element.id = id;
	element.texture = new LPDIRECT3DTEXTURE9();

	HRESULT hr = D3DXCreateTextureFromFileExA(g_pd3dDevice,
		name, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0,
		D3DUSAGE_DYNAMIC,
		D3DFMT_UNKNOWN,
		D3DPOOL_DEFAULT,
		D3DX_DEFAULT,
		D3DX_DEFAULT,
		0,
		nullptr,
		nullptr, element.texture);

	elements.push_back(element);


	/*TextureElement* newElement = new TextureElement();
	newElement->id = id;
	D3DXCreateSprite(g_pd3dDevice, &newElement->sprite);
	D3DXCreateTextureFromFile(g_pd3dDevice, name, &newElement->texture);
	elements.push_back(newElement);*/


}

LPDIRECT3DTEXTURE9* TextureManager::getTexture(int id)
{
	for (int i = 0; i < elements.size(); ++i)
	{
		if (elements[i].id == id)
		{
			return elements[i].texture;
		}
	}
	return nullptr;
}