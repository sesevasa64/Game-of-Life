#pragma once
#include<QPoint>
#include"vec.h"

class Camera {
public:
	Camera() : scale(1.0) {}
	template<class T>
	vec2<T> toWorld(vec2<T>& cam) {
		return (cam / scale) + offset;
	}
	template<class T>
	vec2<T> toCamera(vec2<T>& world) {
		return (world - offset) * scale;
	}
    void SetMousePosition(QPoint& pos);
    void Zoom(QPoint& pos, int wheeldelta);
    void Move(QPoint& pos);
    void MoveByKey(Qt::Key key);
	double getScale() { return scale; }
private:
	vec2d beforeZoom, afterZoom;
	vec2d offset;
	vec2d lastMousePosition;
	double scale;
	static const int keyStep = 10;
};
