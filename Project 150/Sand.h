#pragma once

// ============= Local Header Files ================
#include "TileMap.h"
#include "Particle.h"

 // ============ Standard Includes =================
#include <iostream>
#include <algorithm>

class Sand : public Particle
{
public :
	Sand(particle_t particle)
		: Particle{particle}
	{

	}
	Sand(int32_t x, int32_t y)
		: Particle{ particle_t {x, y, color_t{128,128,0}, Particle_Type::Sand} }
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
		/*
		else if (!isOutSide(m_particle.m_PosX, m_particle.m_PosY + 1) && getType(TileMap::getTile(m_particle.m_PosX, m_particle.m_PosY + 1)) == Particle_Type::Water)
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, TileMap::getTile(m_particle.m_PosX, m_particle.m_PosY + 1));
			goDown();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		*/
		else if (isEmpty(m_particle.m_PosX - 1, m_particle.m_PosY + 1)) // Bottom Left
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goDown();
			goLeft();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		/*
		else if (!isOutSide(m_particle.m_PosX - 1, m_particle.m_PosY + 1) && getType(TileMap::getTile(m_particle.m_PosX - 1, m_particle.m_PosY + 1)) == Particle_Type::Water)
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, TileMap::getTile(m_particle.m_PosX - 1, m_particle.m_PosY + 1));
			goDown();
			goLeft();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		*/
		else if (isEmpty(m_particle.m_PosX + 1, m_particle.m_PosY + 1)) // Bottom Right
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, nullptr);
			goDown();
			goRight();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		/*
		else if (!isOutSide(m_particle.m_PosX + 1, m_particle.m_PosY + 1) && getType(TileMap::getTile(m_particle.m_PosX + 1, m_particle.m_PosY + 1)) == Particle_Type::Water)
		{
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, TileMap::getTile(m_particle.m_PosX + 1, m_particle.m_PosY + 1));
			goDown();
			goRight();
			TileMap::setTile(m_particle.m_PosX, m_particle.m_PosY, this);
		}
		*/
		else
		{
			// stay there
		}
		TileMap::setUpdated(m_particle.m_PosX, m_particle.m_PosY);
	}
};