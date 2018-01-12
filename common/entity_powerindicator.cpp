#include "stdafx.h"
#include "entity_powerindicator.h"
#include "globals.h"
#include "game.h"


PowerIndicator::PowerIndicator()
{

}

PowerIndicator::~PowerIndicator()
{

}

void PowerIndicator::Init(vec2 dim, vec2 pos, vec2 vel)
{
	m_id = EN_POWERINDICATOR;
	m_dim = dim;
	m_pos = pos;
	m_vel = vel;
	m_sprite = new Sprite();
	m_sprite->Init(TEX_POWERINDICATOR, m_dim, m_pos, "power_indicator.png", false);

	game->GetGraphicsEngine()->AddSprite(m_sprite);
}

void PowerIndicator::Run()
{
	// Move power indicator
	if (m_pos.x + (m_dim.x / 2) >= POWERBAR_POS_X + (POWERBAR_DIM_X / 2))
	{
		game->GetWorld()->SetMoveIndicatorLeft(true);
		m_pos.x = (POWERBAR_POS_X + (POWERBAR_DIM_X / 2)) - m_dim.x / 2;
	}

	else if (m_pos.x - (m_dim.x / 2) <= POWERBAR_POS_X - (POWERBAR_DIM_X / 2))
	{
		game->GetWorld()->SetMoveIndicatorLeft(false);
		m_pos.x = (POWERBAR_POS_X - (POWERBAR_DIM_X / 2)) + m_dim.x / 2;
	}

	if	(!game->GetWorld()->GetMoveIndicatorLeft())	m_pos.x += POWER_INDICATOR_SPEED;
	else											m_pos.x -= POWER_INDICATOR_SPEED;

	game->GetWorld()->SetShotPower(m_pos.x / POWERBAR_DIM_X);
}