#pragma once
#ifndef _SPRITE_H_
#define _SPRITE_H_

#include "core.h"


class Sprite
{
public:
	Sprite();
	~Sprite();

	void Init(int id, vec2 dim, vec2 pos, const char* gfxName, bool wrap);

	vec2 GetPos();
	void SetPos(vec2 pos);

	vec2 GetDim();
	void SetDim(vec2 dim);

	GLuint GetGfx();
	void SetGfx(GLuint gfx);

private:
	int m_id;
	vec2 m_pos;
	vec2 m_dim;
	GLuint m_gfx;
};

#endif