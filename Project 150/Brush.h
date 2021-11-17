#pragma once

#include "Application.h"
#include "Manager.h"
#include "Observer.h"
#include "Sand.h"

#include <iostream>

enum class Brush_Type
{
	Pencil,
	Marker,
};

class Brush
{
public :
	Brush(Brush&) = delete;
	static Brush& Get();
	static void setBrush(Brush_Type type);
	static void setColor(color_t color);
	static void setBrushSize(int32_t size);
	static Brush_Type getBrush();
	static color_t getColor();
	static int32_t getBrushSize();
private :
	Brush() = default;
	static Brush_Type m_BrushType;
	static color_t m_BrushColor;
	static int32_t m_BrushSize;
};

