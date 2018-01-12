#pragma once
#ifndef _APPLICATION_MODE_GAME_H_
#define _APPLICATION_MODE_GAME_H_

#include "application_mode.h"


class ApplicationModeGame : public ApplicationMode
{
public:
	ApplicationModeGame();
	~ApplicationModeGame();

	void Init();
	void Restart();

	void ProcessInput();
	void Run();
	void Draw();
};

#endif