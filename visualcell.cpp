#include "visualcell.h"

VisualCell::VisualCell(vec2i& pos, Camera *camera, int size, QColor *color)
    : color(color)
    , pos(pos)
{
    calculate(camera, size);
}

void VisualCell::calculate(Camera *camera, int size)
{
    vec2i p2(pos.x + size, pos.y + size);
    vec2i c1 = camera->toCamera(pos);
    vec2i c2 = camera->toCamera(p2);
    rect.setCoords(c1.x, c1.y, c2.x, c2.y);
}

void VisualCell::draw(QPainter *painter)
{
    painter->fillRect(rect, *color);
}

