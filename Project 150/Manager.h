#pragma once

class Observer;
class Application;

#include "TileMap.h"

#include <vector>

class Manager
{
public :
	Manager();
	void attach(Observer*);
	void detach();
	void update();
	void notify();
private :
	bool scenePlay = true;
	Observer* m_ActiveObserver = nullptr;
	Observer* m_BrushObserver = nullptr;
	Application* m_Application;
	TileMap& m_TileMap = TileMap::get();
};