
//#include "utils.h"

// Override base class with your custom functionality

/*
class Game : public olc::PixelGameEngine
{
public:
	Game()
	{
		// Name your application
		sAppName = "Simulator";
	}

public:
	bool OnUserCreate() override
	{
		// Called once at the start, so create things here
		return true;
	}

	bool OnUserUpdate(float fElapsedTime) override
	{
		// Called once per frame, draws random coloured pixels
		Clear(olc::GREY);

		#if 0
		AssetMgr& mgr = AssetMgr::Get();
		static int32_t x0 = GetMouseX(), y0 = GetMouseY();
		static bool released = false;
		static int8_t key = 1;

		if (GetKey(olc::S).bPressed)
		{
			key = 1;
		}

		if (GetKey(olc::W).bPressed)
		{
			key = 2;
		}

		if (GetKey(olc::A).bPressed)
		{
			key = 3;
		}

		if (GetMouse(olc::Mouse::LEFT).bHeld)
		{
			int32_t x1 = GetMouseX();
			int32_t y1 = GetMouseY();
			if (released)
			{
				x0 = x1;
				y0 = y1;
				released = false;
			}
			int32_t dx = abs(x1 - x0);
			int32_t sx = x0 < x1 ? 1 : -1;
			int32_t dy = -abs(y1 - y0);
			int32_t sy = y0 < y1 ? 1 : -1;
			int32_t err = dx + dy; 
			while (true)  
			{
				//plot(x0, y0);
				mgr.addAsset(new Wood(x0, y0));
				if (x0 == x1 && y0 == y1) break;
				int32_t e2 = 2 * err;
				if (e2 >= dy) 
				{
					err += dy;
					x0 += sx;
				}
				if (e2 <= dx)
				{
					err += dx;
					y0 += sy;
				}
			}
			x0 = x1;
			y0 = y1;
		}

		if (GetMouse(olc::Mouse::LEFT).bReleased)
		{
			released = true;
		}

		if (GetMouse(olc::Mouse::RIGHT).bHeld)
		{
			if (key == 1)
				mgr.addAsset(new Sand(GetMouseX(), GetMouseY()));
			else if (key == 2)
				mgr.addAsset(new Water(GetMouseX(), GetMouseY()));
			else if (key == 3)
				mgr.addAsset(new Acid(GetMouseX(), GetMouseY()));
		}

		//mgr.addAsset(new Sand());
		//mgr.addAsset(new Water());
		mgr.setNotUpdated();
		mgr.update();
		for (Particle* asset : AssetMgr::m_assets)
		{
			Draw(asset->m_particle.m_x, asset->m_particle.m_y, olc::Pixel{asset->m_particle.m_color.r, asset->m_particle.m_color.g, asset->m_particle.m_color.b});
		}
		#endif
		return true;
	}

};
*/
#include "Application.h"

int main()
{
	Application* demo = Application::get("Experiment");
	if (demo->Construct(300, 180, 4, 4, false))
		demo->Start();
	return 0;
}
