//---------------------------------------------------------------------------

#ifndef cellH
#define cellH
#include <Classes.hpp>

class Cell {
public:
	Cell(TPoint p, int color);
	void draw();
	static const int size = 40;
private:
	TPoint p1, p2;
	int color;
};
//---------------------------------------------------------------------------
#endif
