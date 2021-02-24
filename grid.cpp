#include "grid.h"
#include <QDebug>
#include <cmath>

Grid::Grid(Camera* cam)
    : cam(cam)
    , grid_size(cell_size)
{

}

void Grid::update(int Width, int Height) {
    updateBorders(Width, Height);
    updateGrid();
}

void Grid::updateBorders(int Width, int Height) {
	vec2i c1(0, 0), c2(Width, Height);
    w1 = vec2i(cam->toWorld(c1));
    w2 = vec2i(cam->toWorld(c2));
    w1.x = grid_size * floor(w1.x / double(grid_size));
    w1.y = grid_size * floor(w1.y / double(grid_size));
    w2.x = grid_size * ceil(w2.x / double(grid_size));
    w2.y = grid_size * ceil(w2.y / double(grid_size));
}

void Grid::updateGrid() {
    if (grid_size == 0) return;
    int i = 0;
    int size = (abs(w1.x - w2.x) + abs(w1.y - w2.y)) / grid_size;
    grid.resize(size);
    for (int x = w1.x; x < w2.x; x += grid_size) {
        vec2i p1(x, w1.y), p2(x, w2.y);
        vec2i c1 = vec2i(cam->toCamera(p1));
        vec2i c2 = vec2i(cam->toCamera(p2));
        grid[i++] = std::make_pair(c1, c2);
    }
    for (int y = w1.y; y < w2.y; y += grid_size) {
        vec2i p1(w1.x, y), p2(w2.x, y);
        vec2i c1 = vec2i(cam->toCamera(p1));
        vec2i c2 = vec2i(cam->toCamera(p2));
        grid[i++] = std::make_pair(c1, c2);
    }
}

void Grid::setSize(double scale) {
	if (scale < 0.14) {
        grid_size = 0 * cell_size;
	}
	else if (scale < 0.26) {
        grid_size = 4 * cell_size;
	}
	else if (scale < 0.475) {
        grid_size = 2 * cell_size;
	}
	else {
        grid_size = 1 * cell_size;
	}
}

void Grid::drawGrid(QPainter *painter) {
    for (auto& pair : grid) {
        painter->drawLine(pair.first.x, pair.first.y, pair.second.x, pair.second.y);
    }
}
