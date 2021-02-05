#pragma once
#include <unordered_map>
#include <memory>
#include "vec.h"
#include "cell.h"

typedef std::unordered_map<vec2i, std::shared_ptr<Cell>, HashPoint, ComparePoint>::iterator cell_it;
typedef std::unordered_map<vec2i, std::shared_ptr<Cell>, HashPoint, ComparePoint>::const_iterator const_cell_it;

class Colony {
public:
	Colony() {}
	void tick();
	void create(vec2i pos);
	void remove(vec2i pos);
	void remove(cell_it it);
	bool isExist(vec2i pos);
	const_cell_it begin();
	const_cell_it end();
	size_t size();
private:
	std::unordered_map<vec2i, std::shared_ptr<Cell>, HashPoint, ComparePoint> cells;
	std::unordered_map<vec2i, int, HashPoint, ComparePoint> neighbors;
};
