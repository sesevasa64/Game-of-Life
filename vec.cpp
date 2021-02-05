#include "vec.h"

size_t HashPoint::operator()(const vec2i& key) const {
	size_t ret = key.x;
	ret *= 2654435761U;
	return ret ^ key.y;
}

bool ComparePoint::operator()(const vec2i& p1, const vec2i& p2) const {
	return (p1.x == p2.x) && (p1.y == p2.y);
}
