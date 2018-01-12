#pragma once
#ifndef _APPLICATION_MODE_H_
#define _APPLICATION_MODE_H_

class ApplicationMode
{
public:
	virtual void Init() = 0;
	virtual void Restart() = 0;

	virtual void ProcessInput() = 0;
	virtual void Run() = 0;
	virtual void Draw() = 0;

	int m_id;
};

#endif