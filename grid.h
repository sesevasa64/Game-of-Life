#pragma once
#include "colony.h"
#include "camera.h"
#include <memory>
#include <QPainter>

class Grid {
public:
    static const int cell_size = 40;
    Grid(Camera *cam);
	void updateBorders(int Width, int Height);
	void updateSize(double scale);
    void setColor(QColor color);
    void draw(QPainter *painter, Colony* colony);
private:
    void drawGrid(QPainter *painter);
    void drawCell(QPainter *painter, std::shared_ptr<Cell> cell);
    void drawColony(QPainter *painter, Colony* colony);
    QBrush brush;
    Camera *cam;
	vec2i w1, w2;
	int p;
};
