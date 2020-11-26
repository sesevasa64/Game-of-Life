//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Menus.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TTimer *Timer1;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall Timer1Timer(TObject *Sender);
private:	// User declarations
	void __fastcall draw();
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
};

float camX = 0.0f, camY = 0.0f;
float scaleX = 1.0f, scaleY = 1.0f;

// днаюбхрэ оепецпсгйх дкъ рнвей
// хкх бяе фе ядекюрэ ябни йкюяя рнвйх
// х гюлемхрэ бяе щрн цнбмн мю
/*
PointF cam, scale;
void WorldToCam(PointI w, PointI& c) {
	c = (w - cam) * scale;
}
void CamToWorld(PointI c, PointI& w) {
	w = c / scale + cam;
}
*/
void WorldToCam(int wx, int wy, int &cx, int &cy) {
	cx = (wx - camX) * scaleX;
	cy = (wy - camY) * scaleY;
}
void CamToWorld(int cx, int cy, int &wx, int &wy) {
	wx = cx / scaleX + camX;
	wy = cy / scaleY + camY;
}
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
