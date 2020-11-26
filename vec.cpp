//---------------------------------------------------------------------------


#pragma hdrstop

#include "vec.h"

size_t HashPoint::operator()(const TPoint &key) {
	return key.x * 3 + key.y * 5;
}

bool HashPoint::operator()(const TPoint &p1, const TPoint &p2) const {
	if (p1.x == p2.y)
		return p1.x < p2.x;
	return p1.y < p2.y;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
