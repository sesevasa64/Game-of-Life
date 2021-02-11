#pragma once
#include <unordered_map>
#include "visualcell.h"

using VisualCells = std::unordered_map<vec2i, std::shared_ptr<VisualCell>, HashPoint, ComparePoint>;

class CellCollection : public QObject
{
    Q_OBJECT
public:
    CellCollection(Camera *camera);
    void calculate();
    void draw(QPainter *painter);
    void setColor(QColor color);
public slots:
    void add(vec2i& pos);
    void remove(vec2i& pos);
private:
    int cellSize = 40;
    QColor color;
    VisualCells visualCells;
    Camera *camera;
};
