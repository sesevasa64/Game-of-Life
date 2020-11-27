//---------------------------------------------------------------------------

#ifndef gridH
#define gridH

#include<hash_map>
#include<vec.h>
#include<cell.h>
#include<string>

class Grid {
public:
	Grid() {}
	void tick();
	void draw();
	void load_from_file(char *file_name);
	void save_to_file(char *file_name);
private:
	int countNeighbors(vec2i p);
	std::hash_map<vec2i, Cell*, HashPoint> cells;
};
//---------------------------------------------------------------------------
#endif
