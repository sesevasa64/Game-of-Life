#include "colony.h"
#include <list>
using namespace std;

static vec2i dv[] = {
	vec2i(1,  1), vec2i(1,  0),
	vec2i(1, -1), vec2i(0, -1),
	vec2i(-1, -1), vec2i(-1,  0),
	vec2i(-1,  1), vec2i(0,  1)
};

void dummy(const vec2i&) {}

Colony::Colony(callback add, callback remove)
    : whenAdd(add ? add : dummy)
    , whenRemove(remove ? remove : dummy)
{

}

void Colony::eraseAll() {
    for (auto &pos : cells) {
        whenRemove(pos);
        cells.erase(pos);
    }
    for (auto &pair : neighbors) {
        neighbors.erase(pair.first);
    }
}

Colony::~Colony() {
    eraseAll();
}

void Colony::tick() {
    list<vec2i> to_erase;
	list<vec2i> to_create;
    for (auto &pos : cells) {
        int count = neighbors[pos];
		if (count < 2 || 3 < count) {
            to_erase.push_back(pos);
		}
	}
    for (auto &pair : neighbors) {
        int count = neighbors[pair.first];
        if (count == 3 && cells.find(pair.first) == cells.end()) {
            to_create.push_back(pair.first);
		}
	}
    for (auto &pos : to_erase) {
        remove(pos);
	}
    for (auto &pos : to_create) {
        create(pos);
	}
}

void Colony::create(vec2i pos) {
	for (int i = 0; i < 8; i++) {
		neighbors[pos + dv[i]]++;
	}
    cells.insert(pos);
    whenAdd(pos);
}

void Colony::remove(vec2i pos) {
    for (int i = 0; i < 8; i++) {
        vec2i key = pos + dv[i];
        if (--neighbors[key] == 0) {
            neighbors.erase(key);
        }
    }
    cells.erase(pos);
    whenRemove(pos);
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
