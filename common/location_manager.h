#pragma once
#ifndef _LOCATION_MANAGER_H_
#define _LOCATION_MANAGER_H_

#include <vector>
#include <map>


class LocationManager
{
public:
	LocationManager();
	~LocationManager();

	std::string GetText(const char* id);
	void ChangeLanguage();

private:
	std::vector<std::map<std::string, std::string>> m_languages;
	int m_currentLanguage;
};

#endif