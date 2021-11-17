#include "Brush.h"

Brush_Type Brush::m_BrushType = Brush_Type::Pencil;
color_t Brush::m_BrushColor = color_t(0, 0, 0);
int32_t Brush::m_BrushSize = 4;

Brush& Brush::Get()
{
	static Brush s_Instance;
	return s_Instance;
}

void Brush::setBrush(Brush_Type type)
{
	m_BrushType = type;
}

void Brush::setColor(color_t color)
{
	m_BrushColor = color;
}

void Brush::setBrushSize(int32_t size)
{
	m_BrushSize = size;
}

Brush_Type Brush::getBrush()
{
	return m_BrushType;
}

color_t Brush::getColor()
{
	return m_BrushColor;
}

int32_t Brush::getBrushSize()
{
	return m_BrushSize;
}