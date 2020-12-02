//---------------------------------------------------------------------------


#pragma hdrstop
#include "math.h"
#include "camera.h"

void Camera::Move(const TPoint& pos) {
	vec2i MPos(pos.x, pos.y);
	offset -= (MPos - LMP) / scale;
}
void Camera::Zoom(const TPoint& pos, int wheeldelta) {
	vec2f MPos(pos.x, pos.y);
	bZoom = toWorld(MPos);
	if (wheeldelta > 0) {
    	scale *= 1.01f;
	}
	else {
    	scale *= 0.99f;
	}
	aZoom = toWorld(MPos);
	offset += (bZoom - aZoom);
}
void Camera::SetMPos(const TPoint& pos) {
	LMP = vec2f(pos.x, pos.y);
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
void Camera::SelectCell(const TPoint& mpos) {
	vec2f cam(mpos.x, mpos.y);
	vec2i pos = toWorld(cam);
	pos.x = 40 * floor(pos.x / 40.);
	pos.y = 40 * floor(pos.y / 40.);
	Form1->getColony().create(pos, clRed);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
