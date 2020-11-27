//---------------------------------------------------------------------------

#ifndef cellH
#define cellH
#include"vec.h"

class Cell {
public:
	Cell(vec2f p, TColor color);
	Cell(vec2i p, TColor color);
	void draw();
	static const int size = 40;
private:
	vec2f p1, p2;
	int color;
};
//---------------------------------------------------------------------------
#endif
