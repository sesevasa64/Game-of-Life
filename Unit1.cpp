//---------------------------------------------------------------------------
#include <stdio>
#include <vcl.h>
#pragma hdrstop

#include <math.h>
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
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	TPoint mpos(X, Y);
	Camera& cam = Camera::get();
	if (Shift.Contains(ssLeft)) {
    	::ScreenToClient(Form1->Handle, &mpos);
		cam.SetMpos(mpos);
	}
	else {
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
		cam.SetMpos(mpos);
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
	static int i = 0;
	colony.tick();
	Label4->Caption = IntToStr(colony.size());
	Label1->Caption = IntToStr(++i);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormPaint(TObject *Sender)
{
	Camera& cam = Camera::get();
	vec2i c1(0, 0), c2(ClientWidth, ClientHeight);
	vec2i w1 = cam.toWorld(c1), w2 = cam.toWorld(c2);
	int p = 1;
	float scale = cam.getScale();
	if (scale < 0.14) {
		p = 0;
	}
	else if (scale < 0.26) {
		p = 4;
	}
	else if (scale < 0.475) {
		p = 2;
	}
	float size = p * 40.;
	if (size != 0) {
		w1.x = size * floor(w1.x / size);
		w1.y = size * floor(w1.y / size);
		w2.x = size * ceil(w2.x / size);
		w2.y = size * ceil(w2.y / size);
		for (int x = w1.x; x < w2.x; x += size) {
			vec2i p1(x, w1.y), p2(x, w2.y);
			vec2i c1 = cam.toCamera(p1);
			vec2i c2 = cam.toCamera(p2);
			Canvas->MoveTo(c1.x, c1.y);
			Canvas->LineTo(c2.x, c2.y);
		}
		for (int y = w1.y; y < w2.y; y += size) {
			vec2i p1(w1.x, y), p2(w2.x, y);
			vec2i c1 = cam.toCamera(p1);
			vec2i c2 = cam.toCamera(p2);
			Canvas->MoveTo(c1.x, c1.y);
			Canvas->LineTo(c2.x, c2.y);
		}
	}
	colony.draw();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N3Click(TObject *Sender)
{
	Timer2->Enabled = false;
	OpenDialog1->Execute();
	AnsiString str = OpenDialog1->FileName;
	colony = Manager::load_colony(str);
	Timer2->Enabled = true;	
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N4Click(TObject *Sender)
{
	Timer2->Enabled = false;
	SaveDialog1->Execute();
	AnsiString str = SaveDialog1->FileName;
	Manager::save_colony(colony, str);
	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------
void __fastcall TForm1::N6Click(TObject *Sender)
{
	Timer2->Enabled = !Timer2->Enabled;	
}
//---------------------------------------------------------------------------

