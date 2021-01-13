//---------------------------------------------------------------------------

#pragma hdrstop
#include"camera.h"
#include"cell.h"

Cell::Cell(vec2i p, TColor color)
: p1(p.x, p.y), p2(p.x+size, p.y+size), color(color) {}

void Cell::draw() {
	Camera& cam = Camera::get();
	vec2i a = cam.toCamera(p1);
	vec2i b = cam.toCamera(p2);
	TRect r(a.x, a.y, b.x, b.y);
	Form1->Canvas->Brush->Color = color;
	Form1->Canvas->FillRect(r);
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
