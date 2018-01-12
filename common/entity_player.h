#pragma once
#ifndef _ENTITY_PLAYER_H_
#define _ENTITY_PLAYER_H_

#include "entity.h"


class Player : public Entity
{
public:
	Player();
	~Player();

	void Init(vec2 dim, vec2 pos, vec2 vel);
	void Run();
};

#endif