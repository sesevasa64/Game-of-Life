//---------------------------------------------------------------------------


#pragma hdrstop
#include "vec.h"

size_t HashPoint::operator()(const vec2i &key) {
	size_t ret = key.x;
	ret *= 2654435761U;
	return ret ^ key.y;
}
bool HashPoint::operator()(const vec2i &p1, const vec2i &p2) const {
	if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
