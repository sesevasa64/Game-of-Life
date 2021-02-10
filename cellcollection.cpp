#include "cellcollection.h"
#include <QDebug>

CellCollection::CellCollection(Camera *camera)
    : camera(camera)
{

}

void CellCollection::add(vec2i& pos)
{
    vec2i p1 = pos * cellSize;
    visualCells[pos] = std::make_shared<VisualCell>(p1, camera, cellSize);
}

void CellCollection::remove(vec2i& pos)
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
