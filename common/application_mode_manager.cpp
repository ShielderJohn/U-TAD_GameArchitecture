#include "stdafx.h"
#include "application_mode_manager.h"
#include "application_mode_menu.h"
#include "application_mode_game.h"
#include "globals.h"


ApplicationModeManager::ApplicationModeManager()
{
	m_applicationModeList.push_back(new ApplicationModeMenu());
	m_applicationModeList.push_back(new ApplicationModeGame());

	m_activeApplicationMode = AM_MENU;
	m_desiredApplicationMode = NULL;
}

ApplicationModeManager::~ApplicationModeManager()
{
	for (auto vectorIt = m_applicationModeList.begin(); vectorIt != m_applicationModeList.end(); ++vectorIt)
		delete (*vectorIt);

	m_applicationModeList.clear();
}

void ApplicationModeManager::ProcessInput()
{
	m_applicationModeList[m_activeApplicationMode]->ProcessInput();
}

void ApplicationModeManager::Run()
{
	m_applicationModeList[m_activeApplicationMode]->Run();
}

void ApplicationModeManager::Draw()
{
	m_applicationModeList[m_activeApplicationMode]->Draw();
}

void ApplicationModeManager::RequestChangeApplicationMode(int mode)
{
	m_desiredApplicationMode = mode;
}

void ApplicationModeManager::CheckDesiredApplicationMode()
{
	if (m_activeApplicationMode != m_desiredApplicationMode)
	{
		m_applicationModeList[m_activeApplicationMode]->Restart();

		m_activeApplicationMode = m_desiredApplicationMode;
		m_applicationModeList[m_activeApplicationMode]->Init();
	}
}