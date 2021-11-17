#pragma once
#include <vector>

std::vector<std::vector<int8_t>> TileMap(300, std::vector<int8_t>(300));

struct color_t
{
	uint8_t r, g, b, a;
	color_t(uint8_t red, uint8_t green, uint8_t blue, uint8_t alpha = 1)
		: r{red}, g{green}, b{blue}, a{alpha}
	{

	}
};

struct particle_t
{
	int32_t m_x, m_y;
	color_t m_color;
	double m_lifeTime;
	int8_t m_power;
	particle_t()
		: m_color{255, 255, 0, 1}, m_lifeTime{ -1.0f }, m_x{ 120 }, m_y{ 120 },m_power{1}
	{

	}
	particle_t(int32_t x, int32_t y, color_t color, int8_t power = 1)
		: m_x{x}, m_y{y}, m_color{color}, m_lifeTime{ -1.0f }, m_power{power}
	{

	}
};

class Particle
{
public :
	Particle()
		: m_hasUpdated{false}
	{

	}
	Particle(particle_t particle)
		: m_particle{particle}, m_hasUpdated{false}
	{
		TileMap[particle.m_x][particle.m_y] = true;
	}
	virtual void doUpdate()
	{

	}
	virtual void showParticle()
	{
		
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
	bool downEmpty()
	{
		if (m_particle.m_y == 240)
			return false;
		return !(TileMap[m_particle.m_x][m_particle.m_y + 1]);
	}
	bool downLeftEmpty()
	{
		if (m_particle.m_y == 240 || m_particle.m_x == 0)
			return false;
		return !(TileMap[m_particle.m_x - 1][m_particle.m_y + 1]);
	}
	bool downRightEmpty()
	{
		if (m_particle.m_y == 240 || m_particle.m_x == 256)
			return false;
		return !(TileMap[m_particle.m_x + 1][m_particle.m_y + 1]);
	}
	bool leftEmpty()
	{
		if (m_particle.m_x == 0)
			return false;
		return !(TileMap[m_particle.m_x - 1][m_particle.m_y]);
	}
	bool rightEmpty()
	{
		if (m_particle.m_x == 256)
			return false;
		return !(TileMap[m_particle.m_x + 1][m_particle.m_y]);
	}
	void goDown()
	{
		TileMap[m_particle.m_x][m_particle.m_y] = 0;
		m_particle.m_y += 1.0f;
		TileMap[m_particle.m_x][m_particle.m_y] = m_particle.m_power;
	}
	void goDownLeft()
	{
		TileMap[m_particle.m_x][m_particle.m_y] = 0;
		m_particle.m_x -= 1.0f;
		m_particle.m_y += 1.0f;
		TileMap[m_particle.m_x][m_particle.m_y] = m_particle.m_power;
	}
	void goDownRight()
	{
		TileMap[m_particle.m_x][m_particle.m_y] = 0;
		m_particle.m_x += 1.0f;
		m_particle.m_y += 1.0f;
		TileMap[m_particle.m_x][m_particle.m_y] = m_particle.m_power;
	}
	void goLeft()
	{
		TileMap[m_particle.m_x][m_particle.m_y] = 0;
		m_particle.m_x -= 1.0f;
		TileMap[m_particle.m_x][m_particle.m_y] = m_particle.m_power;
	}
	void goRight()
	{
		TileMap[m_particle.m_x][m_particle.m_y] = 0;
		m_particle.m_x += 1.0f;
		TileMap[m_particle.m_x][m_particle.m_y] = m_particle.m_power;
	}
public :
	particle_t m_particle;
	bool m_hasUpdated;
};

class Sand : public Particle
{
public :
	Sand()
		: Particle{}
	{
		
	}
	Sand(int32_t x, int32_t y)
		: Particle (particle_t( x, y, color_t(128,128,0)))
	{

	}
	virtual void doUpdate() override
	{
		if (m_particle.m_y > 240 || m_particle.m_x > 256)
			return;
		if (downEmpty())
		{
			goDown();
		}
		else if (downLeftEmpty())
		{
			goDownLeft();
		}
		else if (downRightEmpty())
		{
			goDownRight();
		}
		else
		{
			// stay there
		}
	}
};

class Water : public Particle
{
public : 
	Water()
		: Particle{}
	{

	}
	Water(int32_t x, int32_t y)
		: Particle(particle_t(x, y, color_t(0, 0, 255)))
	{

	}
	virtual void doUpdate() override
	{
		if (m_particle.m_y > 240 || m_particle.m_x > 256)
			return;
		if (downEmpty())
		{
			goDown();
		}
		else if (downLeftEmpty())
		{
			goDownLeft();
		}
		else if (downRightEmpty())
		{
			goDownRight();
		}
		else if (leftEmpty())
		{
			goLeft();
		}
		else if (rightEmpty())
		{
			goRight();
		}
		else
		{
			// stay there
		}
	}
};

class Wood : public Particle
{
public:
	Wood()
		: Particle{}
	{

	}
	Wood(int32_t x, int32_t y)
		: Particle(particle_t(x, y, color_t(150, 75, 0)))
	{

	}
	virtual void doUpdate() override
	{
		
	}
};

class Acid : public Particle
{
public:
	Acid()
		: Particle{}
	{

	}
	Acid(int32_t x, int32_t y)
		: Particle(particle_t(x, y, color_t(0, 128, 0),2))
	{

	}
	virtual void doUpdate() override
	{
		if (m_particle.m_y == 240 || m_particle.m_x == 256 || m_particle.m_y == 0 || m_particle.m_x == 0)
			return;
		if (TileMap[m_particle.m_x][m_particle.m_y + 1] < m_particle.m_power)
		{
			goDown();
		}
		else if (TileMap[m_particle.m_x - 1][m_particle.m_y + 1] < m_particle.m_power)
		{
			goDownLeft();
		}
		else if (TileMap[m_particle.m_x + 1][m_particle.m_y + 1] < m_particle.m_power)
		{
			goDownRight();
		}
		else if (TileMap[m_particle.m_x + 1][m_particle.m_y] < m_particle.m_power)
		{
			goRight();
		}
		else if (TileMap[m_particle.m_x - 1][m_particle.m_y] < m_particle.m_power)
		{
			goLeft();
		}
		else
		{
			// stay there
		}
	}
};

class AssetMgr
{
public:
	AssetMgr(const AssetMgr&) = delete; // deleting copy constructor
	static AssetMgr& Get()
	{
		static AssetMgr s_Instance; // creating a single instance
		return s_Instance; // returning the single instance
	}
	static void addAsset(Particle* particle)
	{
		m_assets.push_back(particle);
	}
	static void setNotUpdated()
	{
		for (Particle* asset : m_assets)
		{
			asset->setNotUpdated();
		}
	}
	static void update()
	{
		for (Particle* asset : m_assets)
		{
			if (!(asset->updated()))
			{
				asset->doUpdate();
				asset->setUpdated();
			}
		}
	}
	static void show()
	{
		for (Particle* asset : m_assets)
		{
			asset->showParticle();
		}
	}
	static std::vector<Particle*> m_assets;
private:
	AssetMgr() = default; // private default constructor
};

std::vector<Particle*> AssetMgr::m_assets;

/*
class TileMap
{
public :
	TileMap() = delete;
	static void constract(int32_t screenWidth, int32_t screenHeight, int32_t pixelWidth, int32_t pixelHeight)
	{

	}
	static void set(int8_t x, int8_t y)
	{

	}
private :
	std::vector<std::vector<bool>> TileMap;
};
*/