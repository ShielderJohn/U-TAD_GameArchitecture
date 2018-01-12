#pragma once
#ifndef _GLOBALS_H_
#define _GLOBALS_H_

#include <string>


class TextureManager;
class ApplicationModeManager;
class LocationManager;
class FileManager;
class Game;

// ------------------------------------------------------------
// Defines
// ------------------------------------------------------------
#define PLAYER_SPEED 2.5f
#define MAX_PLAYER_SPEED 18.0f
#define FLOOR_FRICTION 0.8f

#define BALL_SPEED 2.5f
#define MAX_BALL_SPEED 28.0f
#define GRAVITY 0.65f
#define AIR_FRICTION 0.78f

#define POWER_INDICATOR_SPEED 4.3f
#define MAX_SHOT_POWER 20.5f

#define BASKETBOARD_DIM_X 48
#define BASKETBOARD_DIM_Y 150
//#define BASKETBOARD_POS_X SCR_WIDTH - BASKETBOARD_DIM_X / 2
//#define BASKETBOARD_POS_Y SCR_HEIGHT - BASKETBOARD_DIM_Y / 1.8f

#define BASKETCASE_DIM_X 98
#define BASKETCASE_DIM_Y 69.5f
//#define BASKETCASE_POS_X SCR_WIDTH - BASKETCASE_DIM_X / 1.02f
//#define BASKETCASE_POS_Y BASKETBOARD_POS_Y - BASKETBOARD_DIM_Y / 2

#define POWERBAR_DIM_X 150
#define POWERBAR_DIM_Y 25
#define POWERBAR_POS_X 100
#define POWERBAR_POS_Y SCR_HEIGHT - 50


// ------------------------------------------------------------
// Global variables
// ------------------------------------------------------------
enum applicationModes { AM_MENU, AM_GAME };
enum entities { EN_PLAYER, EN_BALL, EN_POWERINDICATOR };
enum textures { TEX_BACKGROUND, TEX_PLAYER, TEX_BALL, TEX_BASKETBOARD, TEX_BASKETCASE, TEX_POWERBAR, TEX_POWERINDICATOR };

extern TextureManager* textureManager;
extern ApplicationModeManager* applicationModeManager;
extern LocationManager* locationManager;
extern FileManager* fileManager;
extern Game* game;

extern int selectedLevel;
extern int score;
extern std::string scoreString;

extern float BASKETBOARD_POS_X;
extern float BASKETBOARD_POS_Y;
extern float BASKETCASE_POS_X;
extern float BASKETCASE_POS_Y;

#endif