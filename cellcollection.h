#pragma once
#include <unordered_map>
#include "visualcell.h"
#include "colony.h"

using VisualCells = std::unordered_map<vec2i, std::shared_ptr<VisualCell>, HashPoint, ComparePoint>;

class CellCollection
{
public:
    CellCollection(Camera *camera);
    void calculate();
    void draw(QPainter *painter);
    void setColor(QColor color);
    const callback add, remove;
private:
    void whenAdd(vec2i& pos);
    void whenRemove(vec2i& pos);
    int cellSize = 40;
    QColor color;
    VisualCells visualCells;
    Camera *camera;
};
