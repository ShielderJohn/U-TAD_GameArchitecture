#pragma once
#ifndef _TEXTURE_MANAGER_H_
#define _TEXTURE_MANAGER_H_

#include <map>


class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	GLuint LoadTexture(const char* gfxName, bool wrap);

private:
	std::map<const char*, GLuint> m_loadedTextures;
};

#endif