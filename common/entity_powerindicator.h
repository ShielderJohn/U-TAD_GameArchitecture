#pragma once
#ifndef _ENTITY_POWERINDICATOR_H_
#define _ENTITY_POWERINDICATOR_H_

#include "entity.h"


class PowerIndicator : public Entity
{
public:
	PowerIndicator();
	~PowerIndicator();

	void Init(vec2 dim, vec2 pos, vec2 vel);
	void Run();
};

#endif