#pragma once
#ifndef _APPLICATION_MODE_GAME_H_
#define _APPLICATION_MODE_MANAGER_H_

#include <vector>


class ApplicationMode;

class ApplicationModeManager
{
public:
	ApplicationModeManager();
	~ApplicationModeManager();

	void ProcessInput();
	void Run();
	void Draw();
	void RequestChangeApplicationMode(int mode);
	void CheckDesiredApplicationMode();

private:
	int m_activeApplicationMode;
	int m_desiredApplicationMode;
	std::vector<ApplicationMode*> m_applicationModeList;
};

#endif