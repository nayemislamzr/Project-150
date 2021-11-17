#include "TileMap.h"

#include "Particle.h"

std::vector<std::vector<Particle*>> TileMap::m_Map;

TileMap& TileMap::get()
{
	static TileMap s_Instance;
	return s_Instance;
}

void TileMap::construct(int32_t w, int32_t h)
{
	m_Map = std::vector<std::vector<Particle*>>(w + 50, std::vector<Particle*>(h + 50));
}

void TileMap::setTile(int32_t x, int32_t y, Particle* particle)
{
	//if (m_Map[x][y] != nullptr)
		//delete m_Map[x][y];
	m_Map[x][y] = particle;
}

Particle* TileMap::getTile(int32_t x, int32_t y)
{
	return m_Map[x][y];
}

void TileMap::setUpdated(int32_t x, int32_t y)
{
	m_Map[x][y]->setUpdated();
}

void TileMap::play()
{
	setAllNotUpdated();
	for (int32_t y = 0; y < Application::get()->ScreenHeight(); y++)
	{
		for (int32_t x = 0; x < Application::get()->ScreenWidth(); x++)
		{
			if (TileMap::getTile(x, y) != nullptr)
			{
				m_Map[x][y]->showParticle();
				if (!(m_Map[x][y]->updated()))
					m_Map[x][y]->doUpdate();
			}
		}
	}
}

void TileMap::pause()
{
	for (int32_t y = 0; y < Application::get()->ScreenHeight(); y++)
	{
		for (int32_t x = 0; x < Application::get()->ScreenWidth(); x++)
		{
			if (TileMap::getTile(x, y) != nullptr)
			{
				m_Map[x][y]->showParticle();
			}
		}
	}
}

void TileMap::setAllNotUpdated()
{
	for (int y = 0; y < Application::get()->ScreenHeight(); y++)
	{
		for (int x = 0; x < Application::get()->ScreenWidth(); x++)
		{
			if (m_Map[x][y] != nullptr)
				m_Map[x][y]->setNotUpdated();
		}
	}
}
