#include "stdafx.h"
#include "sys.h"
#include "globals.h"
#include "graphics_engine.h"
#include "location_manager.h"
#include "font.h"


GraphicsEngine::GraphicsEngine()
{

}

GraphicsEngine::~GraphicsEngine()
{
	for (auto vectorIt = m_spriteList.begin(); vectorIt != m_spriteList.end(); ++vectorIt)
		delete (*vectorIt);

	m_spriteList.clear();
}

void GraphicsEngine::Draw()
{
	// Render
	glClear(GL_COLOR_BUFFER_BIT);

	// Draw sprites
	for (std::vector<Sprite*>::iterator it = m_spriteList.begin(); it != m_spriteList.end(); ++it)
		CORE_RenderCenteredSprite((*it)->GetPos(), (*it)->GetDim(), (*it)->GetGfx());

	// Draw score
	FONT_DrawString(vmake((SCR_WIDTH / 2) - 50, SCR_HEIGHT - 55), locationManager->GetText("Score").c_str());
	FONT_DrawString(vmake((SCR_WIDTH / 2) + 70, SCR_HEIGHT - 55), scoreString.c_str());
}

void GraphicsEngine::AddSprite(Sprite* gfx)
{
	m_spriteList.push_back(gfx);
}