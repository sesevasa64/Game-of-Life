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
	: TForm(Owner), grid(Form1->Canvas)
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
		cam.SetMousePosition(mpos);
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
		cam.SetMousePosition(mpos);
	}
	vec2i c1(0, 0), c2(ClientWidth, ClientHeight);
	vec2i w1 = cam.toWorld(c1), w2 = cam.toWorld(c2);
	grid.updateBorders(c1, c2);
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
	grid.updateSize(cam.getScale());
	grid.draw();
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

