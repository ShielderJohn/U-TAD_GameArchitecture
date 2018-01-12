#include "stdafx.h"
#include "game.h"
#include "input_manager.h"
#include "world.h"
#include "graphics_engine.h"


Game::Game()
{
	m_inputManager = new InputManager();
	m_world = new World();
	m_graphicsEngine = new GraphicsEngine();
}

Game::~Game()
{
	delete m_inputManager;
	delete m_world;
	delete m_graphicsEngine;
}

void Game::Init()
{
	m_world->Init();
}

void Game::ProcessInput()
{
	m_inputManager->ProcessInput();
}

void Game::Run()
{
	m_world->Run();
}

void Game::Draw()
{
	m_graphicsEngine->Draw();
}

InputManager* Game::GetInputManager()
{
	return m_inputManager;
}

World* Game::GetWorld()
{
	return m_world;
}

GraphicsEngine* Game::GetGraphicsEngine()
{
	return m_graphicsEngine;
}