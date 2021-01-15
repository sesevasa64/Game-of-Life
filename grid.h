//---------------------------------------------------------------------------

#ifndef gridH
#define gridH
#include <Forms.hpp>
#include "colony.h"
#include "camera.h"

class Grid {
public:
	Grid(TForm *form, Camera *cam);
	void updateBorders();
	void updateSize(float scale);
	void setColor(TColor color);
	void drawGrid();
	void drawCell(Cell *cell);
	void drawColony(Colony& colony);
	static const int cell_size = 40;
private:
	TCanvas *Canvas;
	TForm *Form;
	Camera *cam;
	vec2i w1, w2;
	int p;
};
//---------------------------------------------------------------------------
#endif
