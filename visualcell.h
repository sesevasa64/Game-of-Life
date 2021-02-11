#pragma once
#include <QPainter>
#include <QRect>
#include "camera.h"
#include "vec.h"

class VisualCell 
{
public:
    VisualCell(vec2i& pos, Camera *camera, int size, QColor *color);
    void calculate(Camera *camera, int size);
    void draw(QPainter *painter);
private:
    QColor *color;
    QRect rect;
    vec2i pos;
};
