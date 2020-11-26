//---------------------------------------------------------------------------

#ifndef gridH
#define gridH

#include <hash_map>
#include <cell.h>
#include <vec.h>

class Grid {
public:
	void tick();
private:
	int getNeighbors(TPoint p);
	std::hash_map<TPoint, Cell*, HashPoint> cells;
};
//---------------------------------------------------------------------------
#endif
