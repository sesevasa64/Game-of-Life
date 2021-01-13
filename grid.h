//---------------------------------------------------------------------------

#ifndef gridH
#define gridH
#include "vec.h"

class Grid {
public:
	void updateBorders(vec2i c1, vec2i c2);
	void updateSize(float scale);
	void draw();
private:
	void updateArray();
	float size, p;
	vec2i w1, w2;
};
//---------------------------------------------------------------------------
#endif
