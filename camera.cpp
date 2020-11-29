//---------------------------------------------------------------------------


#pragma hdrstop

#include "camera.h"

void Camera::Move(const TPoint& pos) {
	vec2i MPos(pos.x, pos.y);
	offset -= (MPos - LMP) / scale;
}
void Camera::Zoom(const TPoint& pos, int wheeldelta) {
	vec2f MPos(pos.x, pos.y);
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
#include<fstream>
using namespace std;
void Camera::SelectCell(const TPoint& mpos) {
	vec2f cam(mpos.x, mpos.y);
	vec2i pos;
	toWorld(cam, pos);
	ofstream log("log.txt", ios::app);
	log << "World b: " << pos.x << ", " << pos.y << "\n";
	pos.x = 40 * (pos.x / 40);
	pos.y = 40 * (pos.y / 40);
	log << "World a: " << pos.x << ", " << pos.y << "\n";
    Form1->getGrid().add_cell(pos, clRed);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
