#pragma once

#include "Observer.h"
#include "Sand.h"
#include "Water.h"
#include "Brush.h"

#include <inttypes.h>

class BrushObserver : public Observer
{
public:
	BrushObserver();
	virtual void update() override;
private :
	bool qwe = false;
};

