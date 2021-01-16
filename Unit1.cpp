//---------------------------------------------------------------------------
#include <stdio>
#include <vcl.h>
#pragma hdrstop

#include <math.h>
#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
#include "cell.h"
#include "vec.h"
#include "camera.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
	: TForm(Owner), grid(Form1, &cam)
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
		if (Timer2->Interval > 250) {
			Timer2->Interval -= 250u;
		}
		Label8->Caption = Timer2->Interval;
	}
	// Кнопка -
	else if (Key == VK_OEM_MINUS) {
		Timer2->Interval += 250u;
		Label8->Caption = Timer2->Interval;
	}
	// Стрелочки
	else {
		cam.MoveByKey(Key);
		grid.updateBorders();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	TPoint mpos(X, Y);
	if (Shift.Contains(ssLeft)) {
    	::ScreenToClient(Form1->Handle, &mpos);
		cam.SetMousePosition(mpos);
	}
	else if (Shift.Contains(ssRight)) {
		vec2d c(mpos.x, mpos.y);
		vec2i pos = cam.toWorld(c);
		pos.x = floor(pos.x / double(grid.cell_size));
		pos.y = floor(pos.y / double(grid.cell_size));
		if (colony.isExist(pos)) {
			colony.remove(pos);
		}
		else {
			colony.create(pos);
		}
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
	  int Y)
{
	TPoint mpos(X, Y);
	::ScreenToClient(Form1->Handle, &mpos);
	if (Shift.Contains(ssLeft)) {
		cam.Move(mpos);
		cam.SetMousePosition(mpos);
	}
	grid.updateBorders();
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift,
	  int WheelDelta, TPoint &MousePos, bool &Handled)
{
	::ScreenToClient(Form1->Handle, &MousePos);
	cam.Zoom(MousePos, WheelDelta);
	grid.updateBorders();
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
	grid.updateSize(cam.getScale());
	grid.drawGrid();
	grid.drawColony(colony);
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

void __fastcall TForm1::N5Click(TObject *Sender)
{
	// Утечка памяти
	colony = Colony();	
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N8Click(TObject *Sender)
{
	if (Timer2->Interval > 250) {
    	Timer2->Interval -= 250u;
	}
	Label8->Caption = Timer2->Interval;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N9Click(TObject *Sender)
{
	Timer2->Interval += 250u;
	Label8->Caption = Timer2->Interval;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N10Click(TObject *Sender)
{
	Timer2->Enabled = false;
	if (ColorDialog1->Execute()) {
		grid.setColor(ColorDialog1->Color);
	}
	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------


void __fastcall TForm1::N2Click(TObject *Sender)
{
	Timer2->Enabled = false;
	Form2->ShowModal();
	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormResize(TObject *Sender)
{
	grid.updateBorders();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::N12Click(TObject *Sender)
{
	Timer2->Enabled = false;
	Form3->ShowModal();
	Timer2->Enabled = true;
}
//---------------------------------------------------------------------------


