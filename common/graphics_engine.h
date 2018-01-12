#pragma once
#ifndef _GRAPHICS_ENGINE_H_
#define _GRAPHICS_ENGINE_H_

#include <vector>
#include "sprite.h"
#include "texture_manager.h"


class GraphicsEngine
{
public:
	GraphicsEngine();
	~GraphicsEngine();

	void Draw();
	void AddSprite(Sprite* gfx);

private:
	std::vector<Sprite*> m_spriteList;
};

#endif