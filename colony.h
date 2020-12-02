//---------------------------------------------------------------------------

#ifndef colonyH
#define colonyH

#include<hash_map>
#include"vec.h"
#include"cell.h"

typedef std::hash_map<vec2i, Cell*, HashPoint>::iterator cell_it;
typedef std::hash_map<vec2i, Cell*, HashPoint>::const_iterator const_cell_it;

class Colony {
public:
	Colony() {}
	void tick();
	void draw();
	void create(vec2i pos, TColor color);
	void remove(cell_it it);
	const_cell_it begin();
	const_cell_it end();
	size_t size();
private:
	std::hash_map<vec2i, Cell*, HashPoint> cells;
	std::hash_map<vec2i, int, HashPoint> neighbors;
};
//---------------------------------------------------------------------------
#endif
