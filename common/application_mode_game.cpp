#include "stdafx.h"
#include "application_mode_game.h"
#include "globals.h"
#include "game.h"


ApplicationModeGame::ApplicationModeGame()
{
	if (game == NULL)
		game = new Game();

	m_id = AM_GAME;
}

ApplicationModeGame::~ApplicationModeGame()
{
	delete game;
}

void ApplicationModeGame::Init()
{
	if (game == NULL)
		game = new Game();

	game->Init();
}

void ApplicationModeGame::Restart()
{
	score = 0;
	scoreString = "0";
	delete game;
	game = NULL;
}

void ApplicationModeGame::ProcessInput()
{
	game->ProcessInput();
}

void ApplicationModeGame::Run()
{
	game->Run();
}

void ApplicationModeGame::Draw()
{
	game->Draw();
}