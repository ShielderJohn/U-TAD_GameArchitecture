#include "stdafx.h"
#include "sys.h"
#include "entity_ball.h"
#include "globals.h"
#include "game.h"


Ball::Ball()
{
	
}

Ball::~Ball()
{

}

void Ball::Init(vec2 dim, vec2 pos, vec2 vel)
{
	m_id = EN_BALL;
	m_dim = dim;
	m_pos = pos;
	m_vel = vel;
	m_sprite = new Sprite();
	m_sprite->Init(TEX_BALL, m_dim, m_pos, "ball.png", false);

	game->GetGraphicsEngine()->AddSprite(m_sprite);

	m_isInTheAir = false;
}

void Ball::Run()
{
	Entity* playerEntity = game->GetWorld()->GetEntity(EN_PLAYER);

	// Shoot
	if (game->GetWorld()->GetPlayerShot() && !m_isInTheAir)
	{
		m_vel.y = game->GetWorld()->GetShotPower() * MAX_SHOT_POWER;
		m_vel.x = game->GetWorld()->GetShotPower() * MAX_SHOT_POWER / 2;
		m_isInTheAir = true;
	}

	// Move ball
	if (m_isInTheAir)
	{
		if		(m_vel.x >= MAX_BALL_SPEED)	m_vel.x = MAX_BALL_SPEED;
		else if (m_vel.x < 0)				m_vel.x -= BALL_SPEED;
		else								m_vel.x += BALL_SPEED;

		m_vel.x *= AIR_FRICTION;
		m_vel.y -= GRAVITY;
		m_pos.x += m_vel.x;
		m_pos.y += m_vel.y;
	}

	else m_pos = vadd(playerEntity->GetPos(), m_dim);

	// Ball collisions (window limits)
	if (m_pos.x - (m_dim.x / 2) <= 0)
	{
		m_pos.x = m_dim.x / 2;
		m_vel.x = -m_vel.x / 2;
	}

	if (m_pos.x + (m_dim.x / 2) >= SCR_WIDTH)
	{
		m_pos.x = SCR_WIDTH - m_dim.x / 2;
		m_vel.x = -m_vel.x / 2;
	}

	if (m_pos.y - (m_dim.y / 2) <= 0)
	{
		m_pos.y = m_dim.y / 2;
		m_pos = vadd(playerEntity->GetPos(), m_dim);

		// Update score
		if	(score - 2 <= 0)	score = 0;
		else					score -= 2;
		scoreString = std::to_string(score);

		game->GetWorld()->SetPlayerShot(false);
		m_isInTheAir = false;
	}

	// Ball collisions (basketBoard)
	if (m_pos.y - (m_dim.y / 2) <= BASKETBOARD_POS_Y + (BASKETBOARD_DIM_Y / 2) &&
		m_pos.y + (m_dim.y / 2) >= BASKETBOARD_POS_Y - (BASKETBOARD_DIM_Y / 2))
	{
		if (m_pos.x + (m_dim.x / 2) >= BASKETBOARD_POS_X - (BASKETBOARD_DIM_X / 2))
		{
			m_pos.x = BASKETBOARD_POS_X - (BASKETBOARD_DIM_X / 2) - m_dim.x / 2;
			m_vel.x = -m_vel.x / 2;
		}
	}

	// Score
	if (m_pos.x > BASKETCASE_POS_X - (BASKETCASE_DIM_X / 2) + (BASKETCASE_DIM_X / 4) &&
		(m_pos.y - (m_dim.y / 2)) - (BASKETCASE_POS_Y + (BASKETCASE_DIM_Y / 2)) <= 25.0f &&
		(m_pos.y - (m_dim.y / 2)) - (BASKETCASE_POS_Y + (BASKETCASE_DIM_Y / 2)) > 0.0f)
	{
		game->GetWorld()->SetAboutToScore(true);
	}

	// Collide with basket case (vertical)
	else if (m_pos.x < BASKETCASE_POS_X - (BASKETCASE_DIM_X / 3) &&
		m_pos.x > BASKETCASE_POS_X - (BASKETCASE_DIM_X / 2) - m_dim.x &&
		m_pos.y - (m_dim.y / 2) <= BASKETCASE_POS_Y + (BASKETCASE_DIM_Y / 2) &&
		m_pos.y - (m_dim.y / 2) > BASKETCASE_POS_Y + (BASKETCASE_DIM_Y / 3))
	{
		m_vel.y = -m_vel.y;
	}


	// Collide with basket case (horizontal)
	else if (m_pos.y - (m_dim.y / 2) <= BASKETCASE_POS_Y + (BASKETCASE_DIM_Y / 3) &&
		m_pos.y + (m_dim.y / 2) >= BASKETCASE_POS_Y - (BASKETCASE_DIM_Y / 6))
	{
		if (m_pos.x + (m_dim.x / 2) >= BASKETCASE_POS_X - (BASKETCASE_DIM_X / 2) &&
			m_pos.x + (m_dim.x / 2) < BASKETCASE_POS_X - (BASKETCASE_DIM_X / 4))
		{
			m_pos.x = BASKETCASE_POS_X - (BASKETCASE_DIM_X / 2) - m_dim.x / 2;
			m_vel.x = -m_vel.x / 2;
		}
	}

	// Reset after score
	if (game->GetWorld()->GetAboutToScore())
	{
		if (m_pos.y <= BASKETCASE_POS_Y + (BASKETCASE_DIM_Y / 4) &&
			m_pos.x <= BASKETCASE_POS_X + BASKETCASE_DIM_X &&
			m_pos.x >= BASKETCASE_POS_X - (BASKETCASE_DIM_X / 3))
		{
			m_pos = vadd(playerEntity->GetPos(), m_dim);
			game->GetWorld()->SetPlayerShot(false);
			game->GetWorld()->SetAboutToScore(false);
			m_isInTheAir = false;
			
			// Update score
			score += 5;
			scoreString = std::to_string(score);
		}

	}
}