#pragma once
#ifndef _APPLICATION_MODE_MENU_H_
#define _APPLICATION_MODE_MENU_H_

#include "application_mode.h"


class ApplicationModeMenu : public ApplicationMode
{
public:
	ApplicationModeMenu();
	~ApplicationModeMenu();

	void Init();
	void Restart();

	void ProcessInput();
	void Run();
	void Draw();

private:
	float m_selectorX, m_selectorY;
	int m_selectorPosition;
	bool m_isKeyBeingPressed;
};

#endif