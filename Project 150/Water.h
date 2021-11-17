#pragma once

// ============= Local Header Files ================
#include "Particle.h"

 // ============ Standard Includes =================
#include <iostream>

class Water : public Particle
{
public:
	Water(particle_t particle)
		: Particle{ particle }
	{

	}
	Water(int32_t x, int32_t y)
		: Particle{ particle_t {x, y, color_t{0, 105, 148},  Particle_Type::Water} }
	{

	}
	virtual void doUpdate() override
	{
		if (isEmpty(m_particle.m_PosX, m_particle.m_PosY + 1)) // Bottom
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goDown();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		else if (isEmpty(m_particle.m_PosX - 1, m_particle.m_PosY + 1)) // Bottom Left
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goDown();
			goLeft();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		else if (isEmpty(m_particle.m_PosX + 1, m_particle.m_PosY + 1)) // Bottom Right
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goDown();
			goRight();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		else if (isEmpty(m_particle.m_PosX - 1, m_particle.m_PosY)) // Left
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goLeft();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		else if (isEmpty(m_particle.m_PosX + 1, m_particle.m_PosY)) // Right
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goRight();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		else
		{
			// stay there
		}
		TileMap::setUpdated(m_particle.m_PosX, m_particle.m_PosY);
	}
};