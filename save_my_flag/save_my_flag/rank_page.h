#pragma once
#include "page.h"
#include <vector>
#include <d3dx9.h>

using namespace std;

class RankPage : public Page
{
public:
	RankPage();

	void Update() override;
	void Render() override;

	void Load();
	void Save();

	ID3DXFont* font = NULL;

	bool isFirstStage;

	int buttonState;
};