//---------------------------------------------------------------------------


#pragma hdrstop
#include "grid.h"
#include "camera.h"

void Grid::updateBorders(vec2i c1, vec2i c2) {
	Camera &cam = Camera::get();
	w1 = cam.toWorld(c1);
	w2 = cam.toWorld(c2);
	updateArray();
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
	updateArray();
}
void Grid::updateArray() {

}
/*
void Grid::update(float scale) {
	if (scale < 0.14) {
		p = 0;
	}
	else if (scale < 0.26) {
		p = 4;
	}
	else if (scale < 0.475) {
		p = 2;
	}
}

void Grid::draw() {
	float size = p * 40.;
	if (size != 0) {
		w1.x = size * floor(w1.x / size);
		w1.y = size * floor(w1.y / size);
		w2.x = size * ceil(w2.x / size);
		w2.y = size * ceil(w2.y / size);
		for (int x = w1.x; x < w2.x; x += size) {
			vec2i p1(x, w1.y), p2(x, w2.y);
			vec2i c1 = cam.toCamera(p1);
			vec2i c2 = cam.toCamera(p2);
			Canvas->MoveTo(c1.x, c1.y);
			Canvas->LineTo(c2.x, c2.y);
		}
		for (int y = w1.y; y < w2.y; y += size) {
			vec2i p1(w1.x, y), p2(w2.x, y);
			vec2i c1 = cam.toCamera(p1);
			vec2i c2 = cam.toCamera(p2);
			Canvas->MoveTo(c1.x, c1.y);
			Canvas->LineTo(c2.x, c2.y);
		}
	}
}
*/
//---------------------------------------------------------------------------

#pragma package(smart_init)
