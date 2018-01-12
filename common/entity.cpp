#include "stdafx.h"
#include "entity.h"


Entity::Entity()
{
	m_id = NULL;
	m_dim = { 0, 0 };
	m_pos = { 0, 0 };
	m_vel = { 0, 0 };
	m_sprite = NULL;
}

Entity::~Entity()
{

}

void Entity::Init(vec2 dim, vec2 pos, vec2 vel, std::string gfxName)
{

}

void Entity::Run()
{

}

void Entity::UpdateSprite()
{
	m_sprite->SetDim(m_dim);
	m_sprite->SetPos(m_pos);
}

int Entity::GetId()
{
	return m_id;
}

vec2 Entity::GetDim()
{
	return m_dim;
}

void Entity::SetDim(vec2 dim)
{
	m_dim = dim;
}

vec2 Entity::GetPos()
{
	return m_pos;
}

void Entity::SetPos(vec2 pos)
{
	m_pos = pos;
}

vec2 Entity::GetVel()
{
	return m_vel;
}

void Entity::SetVel(vec2 vel)
{
	m_vel = vel;
}

Sprite* Entity::GetGfx()
{
	return m_sprite;
}

void Entity::SetGfx(Sprite* sprite)
{
	m_sprite = sprite;
}