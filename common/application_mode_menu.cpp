#include "stdafx.h"
#include "sys.h"
#include "globals.h"
#include "location_manager.h"
#include "application_mode_manager.h"
#include "application_mode_menu.h"
#include "game.h"
#include "font.h"


ApplicationModeMenu::ApplicationModeMenu()
{
	m_id = AM_MENU;
	m_selectorX = SCR_WIDTH / 2 - 90;
	m_selectorY = SCR_HEIGHT - 200;
	m_selectorPosition = 0;
	m_isKeyBeingPressed = false;
}

ApplicationModeMenu::~ApplicationModeMenu()
{

}

void ApplicationModeMenu::Init()
{

}

void ApplicationModeMenu::Restart()
{

}

void ApplicationModeMenu::ProcessInput()
{
	//Navigate through menu
	if (SYS_KeyPressed(SYS_KEY_DOWN) && !SYS_KeyPressed(SYS_KEY_UP) && !m_isKeyBeingPressed) {
		m_isKeyBeingPressed = true;

		switch (m_selectorPosition) {
		case 0:
			m_selectorX = SCR_WIDTH / 2 - 90;
			m_selectorY = SCR_HEIGHT - 250;
			m_selectorPosition = 1;
			break;
		case 1:
			m_selectorX = SCR_WIDTH / 2 - 170;
			m_selectorY = SCR_HEIGHT - 300;
			m_selectorPosition = 2;
			break;
		case 2:
			m_selectorX = SCR_WIDTH / 2 - 70;
			m_selectorY = SCR_HEIGHT - 350;
			m_selectorPosition = 3;
			break;
		}
	}

	if (SYS_KeyPressed(SYS_KEY_UP) && !SYS_KeyPressed(SYS_KEY_DOWN) && !m_isKeyBeingPressed) {
		m_isKeyBeingPressed = true;

		switch (m_selectorPosition) {
		case 1:
			m_selectorX = SCR_WIDTH / 2 - 90;
			m_selectorY = SCR_HEIGHT - 200;
			m_selectorPosition = 0;
			break;
		case 2:
			m_selectorX = SCR_WIDTH / 2 - 90;
			m_selectorY = SCR_HEIGHT - 250;
			m_selectorPosition = 1;
			break;
		case 3:
			m_selectorX = SCR_WIDTH / 2 - 170;
			m_selectorY = SCR_HEIGHT - 300;
			m_selectorPosition = 2;
			break;
		}
	}

	// Select option
	if (SYS_KeyPressed(SYS_KEY_ENTER) && !m_isKeyBeingPressed) {
		m_isKeyBeingPressed = true;

		switch (m_selectorPosition) {
		case 0:
			selectedLevel = 0;
			applicationModeManager->RequestChangeApplicationMode(AM_GAME);
			break;
		case 1:
			selectedLevel = 1;
			applicationModeManager->RequestChangeApplicationMode(AM_GAME);
			break;
		case 2:
			locationManager->ChangeLanguage();
			break;
		case 3:
			exit(-1);
			break;
		}
	}

	// Reset keyBeingPressed bool
	if (!SYS_KeyPressed(SYS_KEY_UP) && !SYS_KeyPressed(SYS_KEY_DOWN) && !SYS_KeyPressed(SYS_KEY_ENTER))
		m_isKeyBeingPressed = false;
}

void ApplicationModeMenu::Run()
{
	
}

void ApplicationModeMenu::Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	FONT_DrawString(vmake(SCR_WIDTH / 2 - 110, SCR_HEIGHT - 70), locationManager->GetText("Game title").c_str());
	FONT_DrawString(vmake(SCR_WIDTH / 2 - 60, SCR_HEIGHT - 200), locationManager->GetText("Level 1").c_str());
	FONT_DrawString(vmake(SCR_WIDTH / 2 - 60, SCR_HEIGHT - 250), locationManager->GetText("Level 2").c_str());
	FONT_DrawString(vmake(SCR_WIDTH / 2 - 140, SCR_HEIGHT - 300), locationManager->GetText("Language").c_str());
	FONT_DrawString(vmake(SCR_WIDTH / 2 - 40, SCR_HEIGHT - 350), locationManager->GetText("Exit").c_str());

	FONT_DrawString(vmake(m_selectorX, m_selectorY), "*");
}