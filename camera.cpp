//---------------------------------------------------------------------------


#pragma hdrstop

#include "camera.h"

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
//#include<fstream>
using namespace std;
void Camera::SelectCell(int x, int y) {
	vec2i cam(x, y), pos;
	toWorld(cam, pos);
	pos.x = 40 * (pos.x / 40);
	pos.y = 40 * (pos.y / 40);
	//ofstream log("log.txt", ios::app);
	//log << pos.x << ", " << pos.y << "\n";
    Form1->getGrid().add_cell(pos, clRed);
}
//---------------------------------------------------------------------------

#pragma package(smart_init)
