#pragma once
#ifndef _ENTITY_BALL_H_
#define _ENTITY_BALL_H_

#include "entity.h"


class Ball : public Entity
{
public:
	Ball();
	~Ball();

	void Init(vec2 dim, vec2 pos, vec2 vel);
	void Run();

private:
	bool m_isInTheAir;
};

#endif