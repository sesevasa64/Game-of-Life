#include "camera.h"
#include "math.h"

void Camera::Move(QPoint& pos) {
    vec2i mpos(pos.x(), pos.y());
	offset -= (mpos - lastMousePosition) / scale;
}

void Camera::Zoom(QPoint& pos, int wheeldelta) {
    vec2d mpos(pos.x(), pos.y());
	beforeZoom = toWorld(mpos);
	if (wheeldelta > 0) {
		if (scale < 4.5) {
			scale *= 1.01;
		}
	}
	else {
		scale *= 0.99;
	}
	afterZoom = toWorld(mpos);
	offset += (beforeZoom - afterZoom);
}

void Camera::SetMousePosition(QPoint& pos) {
    lastMousePosition = vec2d(pos.x(), pos.y());
}

void Camera::MoveByKey(Qt::Key key) {
    if (key == Qt::Key_Up) {
		offset.y -= keyStep / scale;
	}
    else if (key == Qt::Key_Down) {
		offset.y += keyStep / scale;
	}
    else if (key == Qt::Key_Left) {
		offset.x -= keyStep / scale;
	}
    else if (key == Qt::Key_Right) {
		offset.x += keyStep / scale;
	}
}
