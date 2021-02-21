#pragma once
#include <d3dx9.h>

class Cloud
{
public:
	virtual void Update() = 0;
	virtual void Render() = 0;

	int classType;

	virtual D3DXVECTOR2 getPos() = 0;
	virtual void setPos(float x, float y) = 0;
	virtual D3DXVECTOR2 getSize() = 0;
	virtual void setSize(float width, float height) = 0;
	virtual int getState() = 0;
	virtual void setState(int state) = 0;
	virtual float getSpeed() = 0;
	virtual void setSpeed(float speed) = 0;
	virtual int getStartPosY() = 0;
	virtual void setStartPosY(int s) = 0;
	virtual bool getIsStart() = 0;
	virtual void setIsStart(bool start) = 0;
};