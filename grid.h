//---------------------------------------------------------------------------

#ifndef gridH
#define gridH
#include <Forms.hpp>
#include <Controls.hpp>
#include "colony.h"
#include "vec.h"

class Grid {
public:
	Grid(TForm *form);
	void updateBorders(vec2i c1, vec2i c2);
	void updateSize(float scale);
	void drawGrid();
	void drawCell(Cell *cell);
	void drawColony(Colony& colony);
	static const int cell_size = 40;
private:
	TCanvas *Canvas;
	vec2i w1, w2;
	int p;
};
//---------------------------------------------------------------------------
#endif
