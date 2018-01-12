#pragma once
#ifndef _GAME_H_
#define _GAME_H_

#include "input_manager.h"
#include "world.h"
#include "graphics_engine.h"


class Game
{
public:
	Game();
	~Game();
	
	void Init();
	void ProcessInput();
	void Run();
	void Draw();

	InputManager* GetInputManager();
	World* GetWorld();
	GraphicsEngine* GetGraphicsEngine();

private:
	InputManager* m_inputManager;
	World* m_world;
	GraphicsEngine* m_graphicsEngine;
};

#endif