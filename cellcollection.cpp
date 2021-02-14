#include "cellcollection.h"
#include <QDebug>

CellCollection::CellCollection(Camera *camera)
    : add(std::bind(&CellCollection::whenAdd, this, std::placeholders::_1))
    , remove(std::bind(&CellCollection::whenRemove, this, std::placeholders::_1))
    , color(Qt::GlobalColor::red)
    , camera(camera)
{

}

void CellCollection::whenAdd(vec2i& pos)
{
    vec2i p1 = pos * cellSize;
    visualCells[pos] = std::make_shared<VisualCell>(p1, camera, cellSize, &color);
}

void CellCollection::whenRemove(vec2i& pos)
{
    visualCells.erase(pos);
}

void CellCollection::calculate()
{
    for (auto &val : visualCells)
    {
        val.second->calculate(camera, cellSize);
    }
}

void CellCollection::draw(QPainter *painter)
{
    for (auto &val : visualCells)
    {
        val.second->draw(painter);
    }
}

void CellCollection::setColor(QColor color) {
    this->color = color;
}
