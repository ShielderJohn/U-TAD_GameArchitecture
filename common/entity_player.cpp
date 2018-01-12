#include "stdafx.h"
#include "sys.h"
#include "entity_player.h"
#include "globals.h"
#include "game.h"


Player::Player()
{

}

Player::~Player()
{

}

void Player::Init(vec2 dim, vec2 pos, vec2 vel)
{
	m_id = EN_PLAYER;
	m_dim = dim;
	m_pos = pos;
	m_vel = vel;
	m_sprite = new Sprite();
	m_sprite->Init(TEX_PLAYER, m_dim, m_pos, "player.png", false);

	game->GetGraphicsEngine()->AddSprite(m_sprite);
}

void Player::Run()
{
	// Move
	if (game->GetWorld()->GetMovingRight())
	{
		if	(m_vel.x >= MAX_PLAYER_SPEED)	m_vel.x = MAX_PLAYER_SPEED;
		else								m_vel.x += PLAYER_SPEED;
	}

	else if (game->GetWorld()->GetMovingLeft())
	{
		if	(m_vel.x <= -MAX_PLAYER_SPEED)	m_vel.x = -MAX_PLAYER_SPEED;
		else								m_vel.x -= PLAYER_SPEED;
	}

	m_vel.x *= FLOOR_FRICTION;
	m_pos.x += m_vel.x;

	// Player Collisions (horizontal limits)
	if (m_pos.x - (m_dim.x / 2) <= 50)	m_pos.x = 50 + (m_dim.x / 2);
	if (m_pos.x + (m_dim.x / 2) >= 350)	m_pos.x = 350 - m_dim.x / 2;
}