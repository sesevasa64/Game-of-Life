#pragma once
#include <QPainter>
#include <QRect>
#include "camera.h"
#include "vec.h"

class VisualCell 
{
public:
    VisualCell(vec2i& pos, Camera *camera, int size);
    void calculate(Camera *camera, int size);
    void draw(QPainter *painter);
private:
    QRect rect;
    vec2i pos;
};
