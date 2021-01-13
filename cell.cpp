//---------------------------------------------------------------------------

#pragma hdrstop
#include"camera.h"
#include"cell.h"

Cell::Cell(vec2i p, TColor color)
: p1(p.x, p.y), p2(p.x + 1, p.y + 1), color(color) {}

//---------------------------------------------------------------------------

#pragma package(smart_init)
