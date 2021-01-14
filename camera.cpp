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

void Camera::MoveByKey(WORD &Key) {
	if (Key == VK_UP) {
		offset.y -= 10 / scale;
	}
	else if (Key == VK_DOWN) {
		offset.y += 10 / scale;
	}
	else if (Key == VK_LEFT) {
		offset.x -= 10 / scale;
	}
	else if (Key == VK_RIGHT) {
		offset.x += 10 / scale;
	}
}

//---------------------------------------------------------------------------

#pragma package(smart_init)
