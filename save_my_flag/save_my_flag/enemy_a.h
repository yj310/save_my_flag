#pragma once
#include <d3dx9.h>
#include "global.h"
#include "enemy.h"

class EnemyA : public Enemy
{
public:
	EnemyA(float x, float y, float direction);
	void Render() override;
	void Update() override;

};