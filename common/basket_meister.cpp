#include "stdafx.h"
#include "core.h"
#include "sys.h"
#include "globals.h"
#include "game.h"
#include "texture_manager.h"
#include "location_manager.h"
#include "application_mode_manager.h"
#include "file_manager.h"
#include "font.h"


// Globals
TextureManager* textureManager = NULL;
ApplicationModeManager* applicationModeManager = NULL;
LocationManager* locationManager = NULL;
FileManager* fileManager = NULL;
Game* game = NULL;

int selectedLevel = -1;
int score = 0;
std::string scoreString = "0";

float BASKETBOARD_POS_X = 0;
float BASKETBOARD_POS_Y = 0;
float BASKETCASE_POS_X = 0;
float BASKETCASE_POS_Y = 0;

int Main(void)
{
	textureManager = new TextureManager();
	applicationModeManager = new ApplicationModeManager();
	locationManager = new LocationManager();
	fileManager = new FileManager();

	// Set up rendering
	glViewport(0, 0, SCR_WIDTH, SCR_HEIGHT); // Sets up clipping
	glClearColor(0.0f, 0.1f, 0.3f, 0.0f);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, SCR_WIDTH, 0.0, SCR_HEIGHT, 0.0, 1.0);
	glEnable(GL_TEXTURE_2D);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	FONT_Init();

	// Main loop
	while (!SYS_GottaQuit())
	{
		applicationModeManager->CheckDesiredApplicationMode();
		applicationModeManager->ProcessInput();
		applicationModeManager->Run();
		applicationModeManager->Draw();

		// Keep system running
		SYS_Show();
		SYS_Pump();
		SYS_Sleep(17);
	}

	delete textureManager;
	delete applicationModeManager;
	delete locationManager;
	delete fileManager;

	return 0;
}
