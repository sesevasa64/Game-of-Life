#pragma once
#include "colony.h"
#include "camera.h"
#include <memory>
#include <QPainter>

class Grid {
public:
    Grid(Camera *cam);
	void updateBorders(int Width, int Height);
	void updateSize(double scale);
    void setColor(QColor color);
    void draw(QPainter *painter, Colony* colony);
	void clear();
	static const int cell_size = 40;
private:
    void drawGrid(QPainter *painter);
    void drawCell(QPainter *painter, std::shared_ptr<Cell> cell);
    void drawColony(QPainter *painter, Colony* colony);
    QPainter *painter;
    QBrush brush;
    Camera *cam;
	vec2i w1, w2;
	int p;
};
