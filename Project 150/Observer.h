#pragma once

class Application;

class Observer
{
public :
	Observer();
	virtual void update() = 0;
protected :
	Application* m_Application = nullptr;
};

