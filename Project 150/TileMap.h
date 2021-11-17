#pragma once

class Particle;

#include "Application.h"

#include <vector>

class TileMap
{
public :
	TileMap(TileMap&) = delete;
	static TileMap& get();
	static void construct(int32_t w, int32_t h);
	static void setTile(int32_t x, int32_t y, Particle* particle);
	static void setUpdated(int32_t x, int32_t y);
	static Particle* getTile(int32_t x, int32_t y);
	static void play();
	static void pause();
private :
	static void setAllNotUpdated();
	TileMap() = default;
	static std::vector<std::vector<Particle*>> m_Map;
};

