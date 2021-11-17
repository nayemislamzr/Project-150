#pragma once

#include "Application.h"
#include "TileMap.h"

#include <vector>

enum class Particle_Type
{
	Sand,
	Water
};

struct color_t
{
	uint8_t r, g, b, a;
	color_t(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 1)
		: r{ red }, g{ green }, b{ blue }, a{ alpha }
	{

	}
};

struct particle_t
{
	int32_t m_PosX, m_PosY;
	color_t m_Color;
	double m_LifeTime;
	Particle_Type m_Type;
	particle_t()
		: m_Color{ 255, 255, 0, 1 }, m_LifeTime{ -1.0f }, m_Type{ Particle_Type::Sand }, m_PosX{ 120 }, m_PosY{ 120 }
	{

	}
	particle_t(int32_t x, int32_t y, color_t color, Particle_Type type,  double life = 1)
		: m_PosX{ x }, m_PosY{ y }, m_Color{ color }, m_Type{ type },  m_LifeTime{ life }
	{

	}
};

class Particle
{
public:
	Particle()
		: m_hasUpdated{ false }
	{

	}
	Particle(particle_t particle)
		: m_particle{ particle }, m_hasUpdated{ false }
	{

	}
	virtual void doUpdate()
	{

	}
	void showParticle()
	{
		Application::get()->Draw(m_particle.m_PosX, m_particle.m_PosY, olc::Pixel{ m_particle.m_Color.r, m_particle.m_Color.g, m_particle.m_Color.b });
	}
	bool updated()
	{
		return m_hasUpdated;
	}
	void setNotUpdated()
	{
		m_hasUpdated = false;
	}
	void setUpdated()
	{
		m_hasUpdated = true;
	}
protected:
	static Particle_Type getType(Particle* particle)
	{
		return particle->m_particle.m_Type;
	}
	static bool isOutSide(int32_t x, int32_t y)
	{
		return (x < 0 || x >= Application::get()->ScreenWidth() || y < 0 || y >= Application::get()->ScreenHeight());
	}
	static bool isEmpty(int32_t x, int32_t y)
	{
		return (!isOutSide(x,y) && TileMap::getTile(x, y) == nullptr);
	}
	void goUp()
	{
		m_particle.m_PosY -= 1;
	}
	void goDown()
	{
		m_particle.m_PosY += 1;
	}
	void goLeft()
	{
		m_particle.m_PosX -= 1;
	}
	void goRight()
	{
		m_particle.m_PosX += 1;
	}
	particle_t m_particle;
	bool m_hasUpdated;
};
