#pragma once
#include <unordered_map>
#include "visualcell.h"

using VisualCells = std::unordered_map<vec2i, std::shared_ptr<VisualCell>, HashPoint, ComparePoint>;

class CellCollection
{
public:
    CellCollection(Camera *camera);
    void add(vec2i& pos);
    void remove(vec2i& pos);
    void calculate();
    void draw(QPainter *painter);
private:
    int cellSize = 40;
    VisualCells visualCells;
    Camera *camera;
};
