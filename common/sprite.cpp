#include "stdafx.h"
#include "sprite.h"
#include "globals.h"
#include "texture_manager.h"


Sprite::Sprite()
{
	m_id = NULL;
	m_pos = { 0, 0 };
	m_dim = { 0, 0 };
	m_gfx = NULL;
}

Sprite::~Sprite()
{

}

void Sprite::Init(int id, vec2 dim, vec2 pos, const char* gfxName, bool wrap)
{
	m_id = id;
	m_dim = dim;
	m_pos = pos;
	m_gfx = textureManager->LoadTexture(gfxName, wrap);
}

vec2 Sprite::GetPos()
{
	return m_pos;
}

void Sprite::SetPos(vec2 pos)
{
	m_pos = pos;
}

vec2 Sprite::GetDim()
{
	return m_dim;
}

void Sprite::SetDim(vec2 dim)
{
	m_dim = dim;
}

GLuint Sprite::GetGfx()
{
	return m_gfx;
}

void Sprite::SetGfx(GLuint sprite)
{
	m_gfx = sprite;
}