//---------------------------------------------------------------------------


#pragma hdrstop

#include "camera.h"

void Camera::toWorld(vec2f cam, vec2f& world) {
	world = cam / scale + offset;
}
void Camera::toCamera(vec2f world, vec2f& cam) {
	cam = (world - offset) * scale;
}
void Camera::Move(int x, int y) {
	vec2f MPos(x, y);
	offset -= (MPos - LMP) / scale;
}
void Camera::Zoom(int x, int y, int wheeldelta) {
	vec2f MPos(x, y);
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
void Camera::SetMPos(int x, int y) {
	LMP = vec2f(x, y);
}
void Camera::ByKey(WORD &Key) {
	if (Key == VK_UP) {
		offset.y -= 10;
	}
	else if (Key == VK_DOWN) {
		offset.y += 10;
	}
	else if (Key == VK_LEFT) {
		offset.x -= 10;
	}
	else if (Key == VK_RIGHT) {
		offset.x += 10;
	}
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
