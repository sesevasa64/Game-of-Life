//---------------------------------------------------------------------------
#include <stdio>
#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "cell.h"
#include "vec.h"
#include "camera.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
int mouseX, mouseY;
int mouseX_bZoom, mouseY_bZoom;
int mouseX_aZoom, mouseY_aZoom;

void __fastcall TForm1::draw() {
    Canvas->Brush->Color = clWhite;
	Canvas->Rectangle(-1, -1, ClientWidth+1, ClientHeight+1);
	Canvas->Brush->Color = clRed;

	//int wx_1 = ClientWidth/2, wy_1 = ClientHeight/2;
	//int wx_2 = wx_1+80, wy_2 = wy_1+60;
	//int cx_1, cy_1, cx_2, cy_2;

	//WorldToCam(wx_1, wy_1, cx_1, cy_1);
	//WorldToCam(wx_2, wy_2, cx_2, cy_2);

	//Canvas->Rectangle(cx_1, cy_1, cx_2, cy_2);
	TPoint p(ClientWidth/2, ClientHeight/2);
	Cell c(p, clRed);
	c.draw();
}

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	if (Key == VK_UP) {
		camY -= 10;
	}
	else if (Key == VK_DOWN) {
		camY += 10;
	}
	else if (Key == VK_LEFT) {
		camX -= 10;
	}
	else if (Key == VK_RIGHT) {
		camX += 10;
	}
	//draw();
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	mouseX = X;
	mouseY = Y;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
	  int Y)
{
	if (Shift.Contains(ssLeft)) {
		camX -= (X - mouseX) / scaleX;
		camY -= (Y - mouseY) / scaleY;
		mouseX = X;
		mouseY = Y;
		//draw();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
	CamToWorld(MousePos.x, MousePos.y, mouseX_bZoom, mouseY_bZoom);
	if (WheelDelta > 0) {
    	scaleX *= 1.01f;
		scaleY *= 1.01f;
	}
	else {
		scaleX *= 0.99f;
		scaleY *= 0.99f;
	}
	CamToWorld(MousePos.x, MousePos.y, mouseX_aZoom, mouseY_aZoom);
    camX += (mouseX_bZoom - mouseX_aZoom);
	camY += (mouseY_bZoom - mouseY_aZoom);
	Handled = true;
	//draw();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	draw();	
}
//---------------------------------------------------------------------------


