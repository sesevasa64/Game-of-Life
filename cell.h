//---------------------------------------------------------------------------

#ifndef cellH
#define cellH
#include "vec.h"
#include <Graphics.hpp>

class Cell {
public:
	static const int size = 40;
	Cell(vec2i p, TColor color);
	void draw();
	vec2i p1, p2;
	TColor color;
};

//---------------------------------------------------------------------------
#endif
