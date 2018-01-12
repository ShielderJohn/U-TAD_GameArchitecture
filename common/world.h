#pragma once
#ifndef _WORLD_H_
#define _WORLD_H_

#include <vector>


class Entity;

class World
{
public:
	World();
	~World();

	void Init();
	void Run();
	void PreRender();
	Entity* GetEntity(int id);

	bool GetMovingRight();
	void SetMovingRight(bool isMovingRight);

	bool GetMovingLeft();
	void SetMovingLeft(bool isMovingLeft);

	bool GetPlayerShot();
	void SetPlayerShot(bool playerShot);

	bool GetAboutToScore();
	void SetAboutToScore(bool isAboutToScore);

	float GetShotPower();
	void SetShotPower(float shotPower);

	bool GetMoveIndicatorLeft();
	void SetMoveIndicatorLeft(bool moveIndicatorLeft);

private:
	std::vector<Entity*> m_entityList;
		
	bool m_isMovingRight;
	bool m_isMovingLeft;
	bool m_playerShot;

	bool m_isAboutToScore;
	float m_shotPower;
	bool m_moveIndicatorLeft;
};

#endif