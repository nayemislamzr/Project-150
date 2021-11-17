#include "BrushObserver.h"

#include "Application.h"

BrushObserver::BrushObserver()
	: Observer{}
{
	std::cout << "Brush Observer created\n";
}

void BrushObserver::update()
{
	if (Application::get()->GetKey(olc::W).bPressed)
	{
		qwe = true;
	}

	if (Application::get()->GetKey(olc::S).bPressed)
	{
		qwe = false;
	}

	int32_t brush_Size = Brush::getBrushSize();
	int32_t pos_X = m_Application->GetMouseX();
	int32_t pos_Y = m_Application->GetMouseY();
	pos_X /= brush_Size;
	pos_Y /= brush_Size;
	pos_X *= brush_Size;
	pos_Y *= brush_Size;
	m_Application->DrawRect(pos_X, pos_Y, brush_Size, brush_Size, olc::Pixel(128, 128, 128));

	if (m_Application->GetMouse(olc::Mouse::LEFT).bHeld)
	{
		for (int y = pos_Y; y < pos_Y + brush_Size; y++)
		{
			for (int x = pos_X; x < pos_X + brush_Size; x++)
			{
				if (qwe)
					TileMap::setTile(x, y, new Water{x, y});
				else TileMap::setTile(x, y, new Sand{ x, y });
			}
		}
	}
}
