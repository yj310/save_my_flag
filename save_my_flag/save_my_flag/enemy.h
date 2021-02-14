#pragma once
#include <d3dx9.h>
#include "global.h"

class Enemy
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	int classType;

	virtual D3DXVECTOR2 getPos() = 0;
	virtual D3DXVECTOR2 getSize() = 0;
	virtual int getState() = 0;
};