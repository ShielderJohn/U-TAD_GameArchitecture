#pragma once
#ifndef _ENTITY_H_
#define _ENTITY_H_

#include "core.h"
#include "sprite.h"


class Entity
{
public:
	Entity();
	~Entity();

	virtual void Init(vec2 dim, vec2 pos, vec2 vel, std::string gfxName);
	virtual void Run();

	void UpdateSprite();
	int GetId();

	vec2 GetDim();
	void SetDim(vec2 dim);

	vec2 GetPos();
	void SetPos(vec2 pos);

	vec2 GetVel();
	void SetVel(vec2 vel);

	Sprite* GetGfx();
	void SetGfx(Sprite* sprite);

protected:
	int m_id;
	vec2 m_dim;
	vec2 m_pos;
	vec2 m_vel;
	Sprite* m_sprite;
};

#endif