#include "stdafx.h"
#include "texture_manager.h"
#include "core.h"


TextureManager::TextureManager()
{

}

TextureManager::~TextureManager()
{
	/*std::map<const char*, GLuint>::iterator it = m_loadedTextures.begin();

	while (it != m_loadedTextures.end())
		CORE_UnloadPNG(it->second);*/

	m_loadedTextures.clear();
}

GLuint TextureManager::LoadTexture(const char* gfxName, bool wrap)
{
	GLuint returnValue;

	if (m_loadedTextures.find(gfxName) != m_loadedTextures.end())
		returnValue = m_loadedTextures[gfxName];
	else
	{
		std::string address("data/");
		address.append(gfxName);

		m_loadedTextures[gfxName] = CORE_LoadPNG(address.c_str(), wrap);
		returnValue = m_loadedTextures[gfxName];
	}

	return returnValue;
}