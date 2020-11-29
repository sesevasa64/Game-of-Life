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
Grid& TForm1::getGrid() {
	return grid;
}
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	// Если нажата кнопка P
	if (Key == 0x50) {
		Timer2->Enabled = !Timer2->Enabled;
	}
	// Кнопка +
	else if (Key == VK_OEM_PLUS) {
		Timer2->Interval -= 250u;
	}
	// Кнопка -
	else if (Key == VK_OEM_MINUS) {
		Timer2->Interval += 250u;
	}
	// Стрелочки
	else {
		Camera::get().ByKey(Key);
	}
}
#include<fstream>
using namespace std;
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	TPoint mpos(X, Y);
	Camera& cam = Camera::get();
	//::ScreenToClient(Form1->Handle, &mpos);
	if (Shift.Contains(ssLeft)) {
    	::ScreenToClient(Form1->Handle, &mpos);
		cam.SetMPos(mpos);
	}
	else {
		ofstream log("log.txt", ios::app);
		log << "Cam before: " << mpos.x << ", " << mpos.y << "\n";
		//::ScreenToClient(Form1->Handle, &mpos);
		log << "Cam after: " << mpos.x << ", " << mpos.y << "\n";
		cam.SelectCell(mpos);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
	  int Y)
{
	TPoint mpos(X, Y);
	::ScreenToClient(Form1->Handle, &mpos);
	Camera& cam = Camera::get();
	if (Shift.Contains(ssLeft)) {
		cam.Move(mpos);
		cam.SetMPos(mpos);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift,
	  int WheelDelta, TPoint &MousePos, bool &Handled)
{
	::ScreenToClient(Form1->Handle, &MousePos);
	Camera& cam = Camera::get();
	cam.Zoom(MousePos, WheelDelta);
	Handled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormCreate(TObject *Sender)
{
	grid.load_from_file("input.txt");
	Form1->DoubleBuffered = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
	Form1->Repaint();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::Timer2Timer(TObject *Sender)
{
	grid.tick();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	grid.draw();
}
//---------------------------------------------------------------------------
