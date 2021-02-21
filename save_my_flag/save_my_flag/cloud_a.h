#pragma once
#include "cloud.h"

class CloudA : public Cloud
{
public:

	CloudA(float x, float y, int direction, int type);
	void Render() override;
	void Update() override;

	/*update*/
	void Normal();
	void Down();
	void UpDown();

	D3DXVECTOR2 getPos() override;
	void setPos(float x, float y) override;
	D3DXVECTOR2 getSize() override;
	void setSize(float width, float height) override;
	int getState() override;
	void setState(int state) override;
	float getSpeed() override;
	void setSpeed(float speed) ;
	int getStartPosY() override;
	void setStartPosY(int s) override;
	bool getIsStart() override;
	void setIsStart(bool start) override;

	bool isStart;
	float start_posY;
	float posX;
	float posY;

	float width;
	float height;

	float speed;

	int img_type;
	int _state;

	int cloud_Y_direction;

	enum cloud_state
	{
		normal,
		down,
		updown
	};

};