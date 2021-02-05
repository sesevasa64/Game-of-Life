#include "grid.h"
#include <cmath>

Grid::Grid(Camera* cam)
    : brush(Qt::red)
    , cam(cam)
    , p(1)
{

}

void Grid::updateBorders(int Width, int Height) {
	vec2i c1(0, 0), c2(Width, Height);
	w1 = cam->toWorld(c1);
	w2 = cam->toWorld(c2);
    float size = p * cell_size;
    w1.x = size * floor(w1.x / size);
    w1.y = size * floor(w1.y / size);
    w2.x = size * ceil(w2.x / size);
    w2.y = size * ceil(w2.y / size);
}

void Grid::updateSize(double scale) {
	if (scale < 0.14) {
		p = 0;
	}
	else if (scale < 0.26) {
		p = 4;
	}
	else if (scale < 0.475) {
		p = 2;
	}
	else {
		p = 1;
	}
}

void Grid::draw(QPainter *painter, Colony *colony)
{
    drawGrid(painter);
    drawColony(painter, colony);
}

void Grid::drawGrid(QPainter *painter) {
	float size = p * cell_size;
	if (size != 0) {
		for (int x = w1.x; x < w2.x; x += size) {
			vec2i p1(x, w1.y), p2(x, w2.y);
			vec2i c1 = cam->toCamera(p1);
			vec2i c2 = cam->toCamera(p2);
            painter->drawLine(c1.x, c1.y, c2.x, c2.y);
		}
		for (int y = w1.y; y < w2.y; y += size) {
			vec2i p1(w1.x, y), p2(w2.x, y);
			vec2i c1 = cam->toCamera(p1);
			vec2i c2 = cam->toCamera(p2);
            painter->drawLine(c1.x, c1.y, c2.x, c2.y);
		}
	}
}

void Grid::drawColony(QPainter *painter, Colony* colony) {
	for (const_cell_it it = colony->begin(); it != colony->end(); it++) {
        drawCell(painter, it->second);
	}
}

void Grid::drawCell(QPainter *painter, std::shared_ptr<Cell> cell) {
	vec2i c1 = cell->p1 * cell_size;
	vec2i c2 = cell->p2 * cell_size;
	vec2i a = cam->toCamera(c1);
	vec2i b = cam->toCamera(c2);
    QPoint p1(a.x, a.y), p2(b.x, b.y);
    QRect r(p1, p2);
    painter->fillRect(r, brush);
}

void Grid::setColor(QColor color) {
    brush.setColor(color);
}
