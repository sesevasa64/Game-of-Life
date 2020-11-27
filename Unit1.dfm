object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Form1'
  ClientHeight = 496
  ClientWidth = 771
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  Menu = MainMenu1
  OldCreateOrder = False
  OnCreate = FormCreate
  OnKeyDown = FormKeyDown
  OnMouseDown = FormMouseDown
  OnMouseMove = FormMouseMove
  OnMouseWheel = FormMouseWheel
  OnPaint = FormPaint
  PixelsPerInch = 96
  TextHeight = 13
  object MainMenu1: TMainMenu
    Left = 728
    Top = 456
    object N1: TMenuItem
      Caption = #1040#1099
    end
    object N2: TMenuItem
      Caption = #1099#1072#1092
      object N3: TMenuItem
        Caption = #1099#1072#1092#1072
      end
    end
  end
  object Timer1: TTimer
    Interval = 14
    OnTimer = Timer1Timer
    Left = 728
    Top = 416
  end
  object Timer2: TTimer
    Interval = 1500
    OnTimer = Timer2Timer
    Left = 728
    Top = 376
  end
end
