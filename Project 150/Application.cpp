#include "Application.h"

#define OLC_PGE_APPLICATION
#include "Engine.h"
#include "Manager.h"

Application* Application::s_Instance = nullptr;

Application::Application()
{
	sAppName = "Game of Life";
}

Application::Application(const std::string& name)
{
	sAppName = name;
}

bool Application::OnUserCreate()
{
	manager = new Manager();
	TileMap::get().construct(ScreenWidth(), ScreenHeight());
	return true;
}

bool Application::OnUserUpdate(float fElapsedTime)
{
	Clear(olc::Pixel(220, 220, 220));

	for (int i = 0; i < ScreenWidth(); i += 4)
	{
		for (int j = 0; j < ScreenHeight(); j += 4)
		{
			DrawRect(i, j, 4, 4, olc::Pixel(192, 192, 192));
		}
	}
	manager->update();
	manager->notify();

	return true;
}

bool Application::OnUserDestroy()
{
	return true;
}

Application* Application::get(const std::string& name)
{
	if (s_Instance == nullptr)
		s_Instance = new Application(name);
	return s_Instance;
}

Application* Application::get()
{
	if (s_Instance == nullptr)
		s_Instance = new Application();
	return s_Instance;
}
