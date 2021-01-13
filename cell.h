//---------------------------------------------------------------------------

#ifndef cellH
#define cellH
#include "vec.h"
#include <Graphics.hpp>

struct Cell {
	Cell(vec2i p, TColor color);
	vec2i p1, p2;
	TColor color;
};

//---------------------------------------------------------------------------
#endif
