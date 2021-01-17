//---------------------------------------------------------------------------

#ifndef gridH
#define gridH
#include <ExtCtrls.hpp>
#include <Forms.hpp>
#include "colony.h"
#include "camera.h"

class Grid {
public:
	Grid(TForm *form, TPaintBox *paintBox, Camera *cam);
	void updateBorders();
	void updateSize(float scale);
	void setColor(TColor color);
	void drawGrid();
	void drawCell(Cell *cell);
	void drawColony(Colony& colony);
	static const int cell_size = 40;
private:
	TPaintBox *PaintBox;
	TCanvas *Canvas;
	TForm *Form;
	Camera *cam;
	vec2i w1, w2;
	int p;
};
//---------------------------------------------------------------------------
#endif
