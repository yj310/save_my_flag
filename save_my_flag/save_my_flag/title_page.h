#pragma once
#include "page.h"
#include <d3dx9.h>


class TitlePage : public Page
{
public:

	TitlePage();
	void Update() override;
	void Render() override;



	int StartButtonState;
	int ExitButtonState;
	float cloud_a_Y;
	float cloud_b_Y;
	float cloud_a_Y_direction;
	float cloud_b_Y_direction;
	float enemy_X;
	int enemy_state;
	int enemy_count;
	float enemy_X_direction;
	int enemy_speed;


	/* Update */
	void StartButtonUpdate(POINT pt);
	void ExitButtonUpdate(POINT pt);
	void CloudUpdate();
	void EnemyUpdate();

	/* Render */
	void BackgroundRender();
	void TitleRender();
	void StartButtonRender();
	void ExitButtonRender();

	void CloudRender();
	void EnemyRender();
	void TileRender();

protected:
	
};