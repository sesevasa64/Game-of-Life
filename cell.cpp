//---------------------------------------------------------------------------


#pragma hdrstop

#include"cell.h"
#include"Unit1.h"

Cell::Cell(TPoint p, int color)
: p1(p), p2(p.x+size, p.y+size), color(color) {}

void Cell::draw() {
	// �����
	int x1, y1, x2, y2;
	// �����
	WorldToCam(p1.x, p1.y, x1, y1);
	// �����
	WorldToCam(p2.x, p2.y, x2, y2);
	// �����
	TRect r(x1, y1, x2, y2);
	Form1->Canvas->Brush->Color = color;
	Form1->Canvas->FillRect(r);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
