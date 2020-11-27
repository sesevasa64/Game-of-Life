//---------------------------------------------------------------------------


#pragma hdrstop

#include"Graphics.hpp"
#include"cell.h"
#include"Unit1.h"
#include"camera.h"

Cell::Cell(vec2f p, TColor color)
: p1(p), p2(p.x+size, p.y+size), color(color) {}

Cell::Cell(vec2i p, TColor color)
: p1(p.x, p.y), p2(p.x+size, p.y+size), color(color) {}

void Cell::draw() {
	Camera& cam = Camera::get();
	vec2f a, b;
	cam.toCamera(p1, a);
	cam.toCamera(p2, b);
	TRect r(a.x, a.y, b.x, b.y);
	Form1->Canvas->Brush->Color = color;
	Form1->Canvas->FillRect(r);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
