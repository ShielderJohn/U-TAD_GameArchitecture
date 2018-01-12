#include "stdafx.h"
#include "world.h"
#include "sys.h"
#include "globals.h"
#include "game.h"
#include "entity_player.h"
#include "entity_ball.h"
#include "entity_powerindicator.h"
#include "file_manager.h"


World::World()
{

}

World::~World()
{
	for (auto vectorIt = m_entityList.begin(); vectorIt != m_entityList.end(); ++vectorIt)
		delete (*vectorIt);

	m_entityList.clear();
}

void World::Init()
{
	// Load level
	fileManager->LoadLevel("../levels.json");

	// Background sprite
	Sprite* background = new Sprite();
	background->Init(TEX_BACKGROUND, vmake(640, 480), vmake(SCR_WIDTH / 2, SCR_HEIGHT / 2), "background2.png", true);
	game->GetGraphicsEngine()->AddSprite(background);

	// Create player
	Player* player = new Player();
	player->Init({ 109.5f, 238.5f }, { 200, 119.25f }, { 0, 0 });

	// Create ball
	Ball* ball = new Ball();
	ball->Init({ 50, 50 }, vadd(player->GetPos(), ball->GetDim()), { 0, 0 });

	// Basket board sprite
	Sprite* basketBoard = new Sprite();
	basketBoard->Init(TEX_BASKETBOARD, { BASKETBOARD_DIM_X, BASKETBOARD_DIM_Y }, { BASKETBOARD_POS_X, BASKETBOARD_POS_Y }, "basket_board.png", false);
	game->GetGraphicsEngine()->AddSprite(basketBoard);

	// Basket case sprite
	Sprite* basketCase = new Sprite();
	basketCase->Init(TEX_BASKETCASE, { BASKETCASE_DIM_X, BASKETCASE_DIM_Y }, { BASKETCASE_POS_X, BASKETCASE_POS_Y }, "basket_case.png", false);
	game->GetGraphicsEngine()->AddSprite(basketCase);

	// Powerbar sprite
	Sprite* powerBar = new Sprite();
	powerBar->Init(TEX_POWERBAR, { POWERBAR_DIM_X, POWERBAR_DIM_Y }, { POWERBAR_POS_X, POWERBAR_POS_Y }, "power_bar.png", false);
	game->GetGraphicsEngine()->AddSprite(powerBar);

	// Create powerindicator
	PowerIndicator* powerIndicator = new PowerIndicator();
	powerIndicator->Init({ 25, 25 }, { 100, SCR_HEIGHT - 50 }, { 0, 0 });

	// Fill entity list
	m_entityList.push_back(player);
	m_entityList.push_back(ball);
	m_entityList.push_back(powerIndicator);

	// Initialize variables
	m_playerShot = false;
	m_isAboutToScore = false;
	m_shotPower = powerIndicator->GetPos().x / POWERBAR_DIM_X;
	m_moveIndicatorLeft = false;
}

void World::Run()
{
	for (std::vector<Entity*>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
		(*it)->Run();

	PreRender();
}

void World::PreRender()
{
	for (std::vector<Entity*>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
		(*it)->UpdateSprite();
}

Entity* World::GetEntity(int id)
{
	Entity* returnValue = NULL;

	for (std::vector<Entity*>::iterator it = m_entityList.begin(); it != m_entityList.end(); ++it)
	{
		if ((*it)->GetId() == id)
		{
			returnValue = (*it);
			break;
		}
	}

	return returnValue;
}

bool World::GetMovingRight()
{
	return m_isMovingRight;
}

void World::SetMovingRight(bool isMovingRight)
{
	m_isMovingRight = isMovingRight;
}

bool World::GetMovingLeft()
{
	return m_isMovingLeft;
}

void World::SetMovingLeft(bool isMovingLeft)
{
	m_isMovingLeft = isMovingLeft;
}

bool World::GetPlayerShot()
{
	return m_playerShot;
}

void World::SetPlayerShot(bool playerShot)
{
	m_playerShot = playerShot;
}

bool World::GetAboutToScore()
{
	return m_isAboutToScore;
}

void World::SetAboutToScore(bool isAboutToScore)
{
	m_isAboutToScore = isAboutToScore;
}

float World::GetShotPower()
{
	return m_shotPower;
}

void World::SetShotPower(float shotPower)
{
	m_shotPower = shotPower;
}

bool World::GetMoveIndicatorLeft()
{
	return m_moveIndicatorLeft;
}

void World::SetMoveIndicatorLeft(bool moveIndicatorLeft)
{
	m_moveIndicatorLeft = moveIndicatorLeft;
}