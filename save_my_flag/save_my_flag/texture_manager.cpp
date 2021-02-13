#include "texture_manager.h"
#include "global.h"

void TextureManager::LoadTexture(const char* filename, int id)
{
    TextureElement element;
    element.id = id;
    element.tex = new LPDIRECT3DTEXTURE9();


    HRESULT hr = D3DXCreateTextureFromFileExA(g_pd3dDevice,
        filename, D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 0,
        D3DUSAGE_DYNAMIC,
        D3DFMT_UNKNOWN,
        D3DPOOL_DEFAULT,
        D3DX_DEFAULT,
        D3DX_DEFAULT,
        0,
        nullptr,
        nullptr, element.tex);

    elements.push_back(element);
}

LPDIRECT3DTEXTURE9* TextureManager::GetTexture(int id)
{
    for (int i = 0; i < elements.size(); ++i)
    {
        if (elements[i].id == id)
        {
            return elements[i].tex;
        }
    }

    return nullptr;
}