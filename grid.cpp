//---------------------------------------------------------------------------


#pragma hdrstop

#include <list>
#include <fstream>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include "grid.h"

using namespace std;

typedef hash_map<vec2i, Cell*, HashPoint>::iterator cell_it;
typedef hash_map<vec2i, bool, HashPoint>::iterator vst_it;
typedef list<cell_it>::iterator list_it;

static vec2i dv[] = {
	vec2i( 40,  40), vec2i( 40,  0),
	vec2i( 40, -40), vec2i( 0, -40),
	vec2i(-40, -40), vec2i(-40,  0),
	vec2i(-40,  40), vec2i( 0,  40)
};

int Grid::countNeighbors(vec2i p) {
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
	hash_map<vec2i, bool, HashPoint> visited;
	for (cell_it it = cells.begin(); it != cells.end(); it++) {
		for (int i = 0; i < 8; i++) {
			vec2i p = it->first + dv[i];
			if (visited.find(p) != visited.end() ||
				cells.find(p) != cells.end()) {
				continue;
			}
			// Чекаем соседние клетки
			int res = countNeighbors(p);
			visited[p] = (res == 3) ? true : false;
		}
		// Чекаем текущую клетку
		int res = countNeighbors(it->first);
		if (res < 2 || 3 < res) {
			erase.push_back(it);
		}
	}
	for (list_it it = erase.begin(); it != erase.end(); it++) {
    	delete (*it)->second;
    	cells.erase(*it);
	}
	for (vst_it it = visited.begin(); it != visited.end(); it++) {
		// Если рядом с гипотетической клеткой 3 соседа
		// то создаем новую клетку
		if (it->second) {
        	add_cell(it->first, clRed);
		}
    }
}

void Grid::draw() {
	for (cell_it it = cells.begin(); it != cells.end(); it++) {
		it->second->draw();
	}
}

void Grid::load_from_file(char *file_name) {
	vec2i p;
	ifstream file(file_name);
    while(file >> p.x >> p.y) {
        cells[p] = new Cell(p, clRed);
    }
}

void Grid::add_cell(vec2i pos, TColor color) {
	cells[pos] = new Cell(pos, color);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
