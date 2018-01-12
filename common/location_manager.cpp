#include "stdafx.h"
#include "location_manager.h"
#include <fstream>
#include "json.hpp"

using json = nlohmann::json;


LocationManager::LocationManager()
{
	json file;
	std::ifstream ifs("../languages.json");
	ifs >> file;

	for (json::iterator it = file.begin(); it != file.end(); ++it)
	{
		std::map<std::string, std::string> language;
		language["Game title"] = (*it).find("Game title")->get<std::string>();
		language["Level 1"] = (*it).find("Level 1")->get<std::string>();
		language["Level 2"] = (*it).find("Level 2")->get<std::string>();
		language["Language"] = (*it).find("Language")->get<std::string>();
		language["Exit"] = (*it).find("Exit")->get<std::string>();
		language["Score"] = (*it).find("Score")->get<std::string>();

		m_languages.push_back(language);
	}

	m_currentLanguage = 0;
}

LocationManager::~LocationManager()
{
	m_languages.clear();
}

std::string LocationManager::GetText(const char* id)
{
	if (m_languages[m_currentLanguage].find(id) != m_languages[m_currentLanguage].end())
		return m_languages[m_currentLanguage][id];
}

void LocationManager::ChangeLanguage()
{
	for (auto it = m_languages.begin(); it != m_languages.end(); ++it)
	{
		if (m_currentLanguage == it - m_languages.begin())
		{
			if (std::next(it) != m_languages.end())
				m_currentLanguage = std::next(it) - m_languages.begin();
			else
				m_currentLanguage = 0;

			break;
		}
	}
}