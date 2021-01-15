//---------------------------------------------------------------------------
#pragma hdrstop
#include "math.h"
#include "grid.h"

Grid::Grid(TForm *form, Camera* cam)
: Form(form), Canvas(form->Canvas), cam(cam), p(1) {
	Canvas->Brush->Color = clRed;
	updateBorders();
}

void Grid::updateBorders() {
	vec2i c1(0, 0), c2(Form->ClientWidth, Form->ClientHeight);
	w1 = cam->toWorld(c1);
	w2 = cam->toWorld(c2);
}

void Grid::updateSize(float scale) {
	if (scale < 0.14) {
		p = 0;
	}
	else if (scale < 0.26) {
		p = 4;
	}
	else if (scale < 0.475) {
		p = 2;
	}
	else {
        p = 1;
	}
}

void Grid::drawGrid() {
	float size = p * cell_size;
	if (size != 0) {
		w1.x = size * floor(w1.x / size);
		w1.y = size * floor(w1.y / size);
		w2.x = size * ceil(w2.x / size);
		w2.y = size * ceil(w2.y / size);
		for (int x = w1.x; x < w2.x; x += size) {
			vec2i p1(x, w1.y), p2(x, w2.y);
			vec2i c1 = cam->toCamera(p1);
			vec2i c2 = cam->toCamera(p2);
			Canvas->MoveTo(c1.x, c1.y);
			Canvas->LineTo(c2.x, c2.y);
		}
		for (int y = w1.y; y < w2.y; y += size) {
			vec2i p1(w1.x, y), p2(w2.x, y);
			vec2i c1 = cam->toCamera(p1);
			vec2i c2 = cam->toCamera(p2);
			Canvas->MoveTo(c1.x, c1.y);
			Canvas->LineTo(c2.x, c2.y);
		}
	}
}

void Grid::drawColony(Colony& colony) {
	for (const_cell_it it = colony.begin(); it != colony.end(); it++) {
		drawCell(it->second);
	}
}

void Grid::drawCell(Cell *cell) {
	vec2i c1 = cell->p1 * cell_size;
	vec2i c2 = cell->p2 * cell_size;
	vec2i a = cam->toCamera(c1);
	vec2i b = cam->toCamera(c2);
	TRect r(a.x, a.y, b.x, b.y);
	Canvas->FillRect(r);
}

void Grid::setColor(TColor color) {
	Canvas->Brush->Color = color;
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
