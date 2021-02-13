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

	/* Update */
	void StartButtonUpdate(POINT pt);

	/* Render */
	void BackgroundRender();
	void StartButtonRender();
protected:
	
};