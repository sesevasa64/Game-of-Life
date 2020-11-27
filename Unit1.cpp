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
void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
	Camera::get().ByKey(Key);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseDown(TObject *Sender, TMouseButton Button,
	  TShiftState Shift, int X, int Y)
{
	Camera::get().SetMPos(X, Y);
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseMove(TObject *Sender, TShiftState Shift, int X,
	  int Y)
{
	Camera& cam = Camera::get();
	if (Shift.Contains(ssLeft)) {
		cam.Move(X, Y);
		cam.SetMPos(X, Y);
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm1::FormMouseWheel(TObject *Sender, TShiftState Shift,
      int WheelDelta, TPoint &MousePos, bool &Handled)
{
	Camera& cam = Camera::get();
	cam.Zoom(MousePos.x, MousePos.y, WheelDelta);
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
	//Canvas->Brush->Color = clWhite;
	//Canvas->Rectangle(-1, -1, ClientWidth+1, ClientHeight+1);
	//Canvas->Brush->Color = clRed;
	grid.draw();
}
//---------------------------------------------------------------------------

