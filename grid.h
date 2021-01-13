//---------------------------------------------------------------------------

#ifndef gridH
#define gridH
#include <Controls.hpp>
#include "vec.h"

class Grid {
public:
	Grid(TCanvas *canvas) : Canvas(canvas), p(1) {}
	void updateBorders(vec2i c1, vec2i c2);
	void updateSize(float scale);
	void draw();
private:
	TCanvas *Canvas;
	float size, p;
	vec2i w1, w2;
};
//---------------------------------------------------------------------------
#endif
