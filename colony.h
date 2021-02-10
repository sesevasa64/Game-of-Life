#pragma once
#include <unordered_set>
#include <functional>
#include <memory>
#include "vec.h"

using cell_it = std::unordered_set<vec2i, HashPoint, ComparePoint>::iterator;
using const_cell_it = std::unordered_set<vec2i, HashPoint, ComparePoint>::const_iterator;
using callback = std::function<void(vec2i&)>;

class Colony {
public:
    Colony(callback addCell = nullptr, callback removeCell = nullptr);
	void tick();
	void create(vec2i pos);
	void remove(vec2i pos);
	void remove(cell_it it);
	bool isExist(vec2i pos);
	const_cell_it begin();
	const_cell_it end();
	size_t size();
private:
    std::unordered_set<vec2i, HashPoint, ComparePoint> cells;
    std::unordered_map<vec2i, int, HashPoint, ComparePoint> neighbors;
    callback whenCreate, whenRemove;
};
