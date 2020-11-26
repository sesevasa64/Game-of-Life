//---------------------------------------------------------------------------


#pragma hdrstop

#include <list>
#include <Graphics.hpp>
#include "grid.h"

using namespace std;

typedef hash_map<TPoint, Cell*, HashPoint>::iterator cell_it;
typedef hash_map<TPoint, bool, HashPoint>::iterator vst_it;
typedef list<cell_it>::iterator list_it;

static TPoint dv[] = {
	Point( 1,  1), Point( 1,  0),
	Point( 1, -1), Point( 0, -1),
	Point(-1, -1), Point(-1,  0),
	Point(-1,  0), Point( 0,  1)
};

int Grid::getNeighbors(TPoint p) {
	int count = 0;
	for (int i = 0; i < 8; i++) {
		if (cells.find(p + dv[i]) != cells.end()) {
        	count++;
		}
	}
	return count;
}

void Grid::tick() {
	list<cell_it> erase;
	hash_map<TPoint, bool, HashPoint> visited;
	for (cell_it it = cells.begin(); it != cells.end(); it++) {
		for (int i = 0; i < 8; i++) {
			TPoint p = it->first + dv[i];
			if (visited.find(p) != visited.end() ||
				cells.find(p) != cells.end()) {
				continue;
			}
			// Чекаем соседние клетки
			int res = getNeighbors(p);
			visited[p] = res == 3 ? true : false;
		}
		// Чекаем текущую клетку
		int res = getNeighbors(it->first);
		if (res < 2 || 3 < res) {
			erase.push_back(it);
		}
	}
	for (list_it it = erase.begin(); it != erase.end(); it++) {
    	cells.erase(*it);
	}
	for (vst_it it = visited.begin(); it != visited.end(); it++) {
		if (it->second) {
        	cells[it->first] = new Cell(it->first, clRed);
		}
    }
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
