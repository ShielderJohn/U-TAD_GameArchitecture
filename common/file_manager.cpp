#include "stdafx.h"
#include "sys.h"
#include "globals.h"
#include "file_manager.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;


FileManager::FileManager()
{

}

FileManager::~FileManager()
{

}

void FileManager::LoadLevel(const char* filename)
{
	json file;
	std::ifstream ifs(filename);
	ifs >> file;
	
	int counter = 0;

	for (json::iterator it = file.begin(); it != file.end(); ++it)
	{
		if (counter == selectedLevel)
		{
			BASKETBOARD_POS_X = SCR_WIDTH - (*it).find("basketboard_pos_x")->get<float>();
			BASKETBOARD_POS_Y = SCR_HEIGHT - (*it).find("basketboard_pos_y")->get<float>();
			BASKETCASE_POS_X = SCR_WIDTH - (*it).find("basketcase_pos_x")->get<float>();
			BASKETCASE_POS_Y = BASKETBOARD_POS_Y - (*it).find("basketcase_pos_y")->get<float>();

			break;
		}

		counter += 1;
	}
}