#include "cheat.h"
#include "global.h"

void Cheat::Update()
{
	if (inputManager.prevKeyBuffer[VK_F1] == 1 && inputManager.keyBuffer[VK_F1] == 0)
	{
		pageManager.CreateTitlePage();
	}
	if (inputManager.prevKeyBuffer[VK_F2] == 1 && inputManager.keyBuffer[VK_F2] == 0)
	{
		pageManager.CreateFirstGamePage();
	}
}