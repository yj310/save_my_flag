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

	/* Update */
	void StartButtonUpdate(POINT pt);
	void ExitButtonUpdate(POINT pt);

	/* Render */
	void BackgroundRender();
	void TitleRender();
	void StartButtonRender();
	void ExitButtonRender();

protected:
	
};