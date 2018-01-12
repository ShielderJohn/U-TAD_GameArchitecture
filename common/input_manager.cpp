#include "stdafx.h"
#include "sys.h"
#include "globals.h"
#include "input_manager.h"
#include "application_mode_manager.h"
#include "game.h"


InputManager::InputManager()
{

}

InputManager::~InputManager()
{

}

void InputManager::ProcessInput()
{
	// Move player
	if (SYS_KeyPressed(SYS_KEY_RIGHT) && !SYS_KeyPressed(SYS_KEY_LEFT))
		game->GetWorld()->SetMovingRight(true);
	else if (SYS_KeyPressed(SYS_KEY_LEFT) && !SYS_KeyPressed(SYS_KEY_RIGHT))
		game->GetWorld()->SetMovingLeft(true);
	else
	{
		game->GetWorld()->SetMovingRight(false);
		game->GetWorld()->SetMovingLeft(false);
	}

	// Shoot
	if (SYS_KeyPressed(SYS_KEY_UP) && !game->GetWorld()->GetPlayerShot())
		game->GetWorld()->SetPlayerShot(true);

	// Exit to menu
	if (SYS_KeyPressed(SYS_KEY_ESC))
		applicationModeManager->RequestChangeApplicationMode(AM_MENU);
}