//---------------------------------------------------------------------------


#pragma hdrstop

#include <list>
#include <fstream>
#include <Graphics.hpp>
#include <Dialogs.hpp>
#include "colony.h"
using namespace std;

typedef hash_map<vec2i, int, HashPoint>::iterator n_it;
typedef hash_map<vec2i, bool, HashPoint>::iterator vst_it;
typedef list<cell_it>::iterator erase_it;
typedef list<vec2i>::iterator create_it;

static vec2i dv[] = {
	vec2i( 40,  40), vec2i( 40,  0),
	vec2i( 40, -40), vec2i( 0, -40),
	vec2i(-40, -40), vec2i(-40,  0),
	vec2i(-40,  40), vec2i( 0,  40)
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
    	create(*it, clRed);
	}
}

void Colony::create(vec2i pos, TColor color) {
	for (int i = 0; i < 8; i++) {
		neighbors[pos + dv[i]]++;
	}
	cells[pos] = new Cell(pos, color);
}

void Colony::remove(cell_it it) {
	for (int i = 0; i < 8; i++) {
		vec2i key = it->first + dv[i];
		if (--neighbors[key] == 0) {
			neighbors.erase(key);
		}
	}
	delete it->second;
	cells.erase(it);
}

void Colony::remove(vec2i pos) {
	for (int i = 0; i < 8; i++) {
	vec2i key = pos + dv[i];
		if (--neighbors[key] == 0) {
			neighbors.erase(key);
		}
	}
	delete cells[pos];
	cells.erase(pos);
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

void Colony::draw() {
	for (cell_it it = cells.begin(); it != cells.end(); it++) {
		it->second->draw();
	}
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
