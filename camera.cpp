//---------------------------------------------------------------------------


#pragma hdrstop

#include "camera.h"

template<typename T, typename U>
void Camera::toWorld(vec2<T> cam, vec2<U>& world) {
	world = cam / scale + offset;
}
template<typename T, typename U>
void Camera::toCamera(vec2<T> world, vec2<U>& cam) {
	cam = (world - offset) * scale;
}
void Camera::Move(vec2i MPos) {
	offset -= (MPos - LMP) / scale;
}
void Camera::Zoom(vec2i MPos, int wheeldelta) {
	toWorld(MPos, bZoom);
	if (wheeldelta > 0) {
    	scale *= 1.01f;
	}
	else {
    	scale *= 0.99f;
	}
	toWorld(MPos, aZoom);
	offset += (bZoom - aZoom);
}
void Camera::SetMPos(vec2i MPos) {
	LMP = MPos;
}
vec2f& Camera::Offset() {
	return offset;
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
