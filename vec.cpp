//---------------------------------------------------------------------------


#pragma hdrstop
#include <fstream>
#include "vec.h"

using namespace std;

size_t HashPoint::operator()(const vec2i &key) {
	size_t ret = key.x;
	ret *= 2654435761U;
	//ofstream myfile("log.txt", ios::app);
	//myfile << key.x << ", " << key.y << ", " << (ret ^ key.y) << "\n";
	return ret ^ key.y;
}
#include"math.h"
bool HashPoint::operator()(const vec2i &p1, const vec2i &p2) const {
	if (p1.x == p2.x) {
		return p1.y < p2.y;
	}
	return p1.x < p2.x;
	//return sqrt(p1.x*p1.x+p1.y*p1.y) < sqrt(p2.x*p2.x+p2.y*p2.y);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
