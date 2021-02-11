#include "grid.h"
#include <cmath>

Grid::Grid(Camera* cam)
    : cam(cam)
    , grid_size(cell_size)
{

}

void Grid::updateBorders(int Width, int Height) {
	vec2i c1(0, 0), c2(Width, Height);
	w1 = cam->toWorld(c1);
	w2 = cam->toWorld(c2);
    w1.x = grid_size * floor(w1.x / double(grid_size));
    w1.y = grid_size * floor(w1.y / double(grid_size));
    w2.x = grid_size * ceil(w2.x / double(grid_size));
    w2.y = grid_size * ceil(w2.y / double(grid_size));
}

void Grid::updateSize(double scale) {
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
    if (grid_size == 0) return;
    for (int x = w1.x; x < w2.x; x += grid_size) {
        vec2i p1(x, w1.y), p2(x, w2.y);
        vec2i c1 = cam->toCamera(p1);
        vec2i c2 = cam->toCamera(p2);
        painter->drawLine(c1.x, c1.y, c2.x, c2.y);
    }
    for (int y = w1.y; y < w2.y; y += grid_size) {
        vec2i p1(w1.x, y), p2(w2.x, y);
        vec2i c1 = cam->toCamera(p1);
        vec2i c2 = cam->toCamera(p2);
        painter->drawLine(c1.x, c1.y, c2.x, c2.y);
    }
}
