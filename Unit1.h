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
#include <Dialogs.hpp>
#include "manager.h"
#include "grid.h"
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TTimer *Timer1;
	TTimer *Timer2;
	TLabel *Label1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TMenuItem *N3;
	TMenuItem *N4;
	TOpenDialog *OpenDialog1;
	TSaveDialog *SaveDialog1;
	TMenuItem *N5;
	TLabel *Label5;
	TLabel *Label6;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N9;
	TMenuItem *N10;
	TColorDialog *ColorDialog1;
	void __fastcall FormKeyDown(TObject *Sender, WORD &Key, TShiftState Shift);
	void __fastcall FormMouseDown(TObject *Sender, TMouseButton Button,
          TShiftState Shift, int X, int Y);
	void __fastcall FormMouseMove(TObject *Sender, TShiftState Shift, int X,
          int Y);
	void __fastcall FormMouseWheel(TObject *Sender, TShiftState Shift,
          int WheelDelta, TPoint &MousePos, bool &Handled);
	void __fastcall Timer1Timer(TObject *Sender);
	void __fastcall FormCreate(TObject *Sender);
	void __fastcall Timer2Timer(TObject *Sender);
	void __fastcall FormPaint(TObject *Sender);
	void __fastcall N3Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N6Click(TObject *Sender);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N8Click(TObject *Sender);
	void __fastcall N9Click(TObject *Sender);
	void __fastcall N10Click(TObject *Sender);
private:	// User declarations
	Colony colony;
	Grid grid;
public:		// User declarations
	__fastcall TForm1(TComponent* Owner);
	Colony& getColony() { return colony; };
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------

#endif
