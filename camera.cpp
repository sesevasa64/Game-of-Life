//---------------------------------------------------------------------------

#pragma hdrstop
#include "math.h"
#include "camera.h"

void Camera::Move(const TPoint& pos) {
	vec2i mpos(pos.x, pos.y);
	offset -= (mpos - lastMousePosition) / scale;
}

void Camera::Zoom(const TPoint& pos, int wheeldelta) {
	vec2f mpos(pos.x, pos.y);
	beforeZoom = toWorld(mpos);
	if (wheeldelta > 0) {
		scale *= 1.01f;
	}
	else {
		scale *= 0.99f;
	}
	afterZoom = toWorld(mpos);
	offset += (beforeZoom - afterZoom);
	Form1->Label6->Caption = FloatToStr(scale);
}

void Camera::SetMousePosition(const TPoint& pos) {
	lastMousePosition = vec2f(pos.x, pos.y);
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
	Colony& colony = Form1->getColony();
	if (colony.isExist(pos)) {
    	colony.remove(pos);
	}
	else {
		colony.create(pos, clRed);
	}
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
