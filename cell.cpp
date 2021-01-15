//---------------------------------------------------------------------------

#pragma hdrstop
#include"camera.h"
#include"cell.h"

Cell::Cell(vec2i p) : p1(p.x, p.y), p2(p.x + 1, p.y + 1) {}

//---------------------------------------------------------------------------

#pragma package(smart_init)
