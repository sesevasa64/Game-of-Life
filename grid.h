#pragma once
#include "colony.h"
#include "camera.h"
#include <memory>
#include <QPainter>

class Grid {
public:
    static const int cell_size = 40;
    Grid(Camera *cam);
    void setSize(double scale);
    void update(int Width, int Height);
    void drawGrid(QPainter *painter);
private:
    void updateBorders(int Width, int Height);
    void updateGrid();
    std::vector<std::pair<vec2i, vec2i>> grid;
    Camera *cam;
	vec2i w1, w2;
    int grid_size;
};
