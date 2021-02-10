#include "colony.h"
#include <list>
using namespace std;

using n_it = unordered_map<vec2i, int, HashPoint, ComparePoint>::iterator;
using vst_it = unordered_map<vec2i, bool, HashPoint, ComparePoint>::iterator;
using erase_it = list<cell_it>::iterator;
using create_it = list<vec2i>::iterator;

static vec2i dv[] = {
	vec2i(1,  1), vec2i(1,  0),
	vec2i(1, -1), vec2i(0, -1),
	vec2i(-1, -1), vec2i(-1,  0),
	vec2i(-1,  1), vec2i(0,  1)
};

void Colony::tick() {
	list<cell_it> to_erase;
	list<vec2i> to_create;
	for (cell_it it = cells.begin(); it != cells.end(); it++) {
		int count = neighbors[it->first];
		if (count < 2 || 3 < count) {
			to_erase.push_back(it);
		}
	}
	for (n_it it = neighbors.begin(); it != neighbors.end(); it++) {
		int count = neighbors[it->first];
		if (count == 3 && cells.find(it->first) == cells.end()) {
			to_create.push_back(it->first);
		}
	}
	for (erase_it it = to_erase.begin(); it != to_erase.end(); it++) {
		remove(*it);
	}
	for (create_it it = to_create.begin(); it != to_create.end(); it++) {
		create(*it);
	}
}

void Colony::create(vec2i pos) {
	for (int i = 0; i < 8; i++) {
		neighbors[pos + dv[i]]++;
	}
	cells[pos] = make_shared<Cell>(pos);
}

void Colony::remove(vec2i pos) {
	remove(cells.find(pos));
}

void Colony::remove(cell_it it) {
	for (int i = 0; i < 8; i++) {
		vec2i key = it->first + dv[i];
		if (--neighbors[key] == 0) {
			neighbors.erase(key);
		}
	}
	cells.erase(it);
}

bool Colony::isExist(vec2i pos) {
	return cells.find(pos) != cells.end();
}

size_t Colony::size() {
	return cells.size();
}

const_cell_it Colony::begin() {
	return cells.begin();
}

const_cell_it Colony::end() {
	return cells.end();
}
