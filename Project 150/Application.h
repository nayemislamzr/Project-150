#pragma once

class Manager;

#include "Engine.h"

class Application : public olc::PixelGameEngine
{
public:
	Application(Application&) = delete;
	virtual bool OnUserCreate() override;
	virtual bool OnUserUpdate(float fElapsedTime) override;
	virtual bool OnUserDestroy() override;
	static Application* get(const std::string& name);
	static Application* get();
private:
	Application();
	Application(const std::string& name);
	static Application* s_Instance;
	Manager* manager = nullptr;
};
