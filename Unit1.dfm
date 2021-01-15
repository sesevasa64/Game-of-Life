object Form1: TForm1
  Left = 0
  Top = 0
  Caption = 'Game of Life'
  ClientHeight = 603
  ClientWidth = 762
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
  OnResize = FormResize
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 100
    Top = 27
    Width = 9
    Height = 19
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label2: TLabel
    Left = 8
    Top = 27
    Width = 86
    Height = 19
    Caption = #1055#1086#1082#1086#1083#1077#1085#1080#1077':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label3: TLabel
    Left = 8
    Top = 52
    Width = 58
    Height = 19
    Caption = #1050#1083#1077#1090#1086#1082':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label4: TLabel
    Left = 72
    Top = 52
    Width = 9
    Height = 19
    Caption = '0'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label5: TLabel
    Left = 8
    Top = 2
    Width = 33
    Height = 19
    Caption = #1047#1091#1084':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label6: TLabel
    Left = 47
    Top = 2
    Width = 9
    Height = 19
    Caption = '1'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label7: TLabel
    Left = 8
    Top = 77
    Width = 74
    Height = 19
    Caption = #1057#1082#1086#1088#1086#1089#1090#1100':'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object Label8: TLabel
    Left = 88
    Top = 77
    Width = 36
    Height = 19
    Caption = '1500'
    Font.Charset = DEFAULT_CHARSET
    Font.Color = clWindowText
    Font.Height = -16
    Font.Name = 'Tahoma'
    Font.Style = []
    ParentFont = False
  end
  object MainMenu1: TMainMenu
    Left = 728
    Top = 496
    object N1: TMenuItem
      Caption = #1048#1075#1088#1072
      object N3: TMenuItem
        Caption = #1047#1072#1075#1088#1091#1079#1080#1090#1100' '#1080#1079' '#1092#1072#1081#1083#1072
        OnClick = N3Click
      end
      object N4: TMenuItem
        Caption = #1057#1086#1093#1088#1072#1085#1080#1090#1100' '#1074' '#1092#1072#1081#1083
        OnClick = N4Click
      end
      object N5: TMenuItem
        Caption = #1057#1090#1077#1088#1077#1090#1100' '#1074#1089#1077
        OnClick = N5Click
      end
      object N6: TMenuItem
        Caption = #1055#1072#1091#1079#1072' / '#1042#1086#1079#1086#1073#1085#1086#1074#1080#1090#1100
        OnClick = N6Click
      end
    end
    object N7: TMenuItem
      Caption = #1057#1082#1086#1088#1086#1089#1090#1100
      object N8: TMenuItem
        Caption = #1059#1074#1077#1083#1080#1095#1080#1090#1100
        OnClick = N8Click
      end
      object N9: TMenuItem
        Caption = #1059#1084#1077#1085#1100#1096#1080#1090#1100
        OnClick = N9Click
      end
    end
    object N10: TMenuItem
      Caption = #1062#1074#1077#1090' '#1082#1083#1077#1090#1082#1080
      OnClick = N10Click
    end
    object N11: TMenuItem
      Caption = #1057#1087#1088#1072#1074#1082#1072
      object N2: TMenuItem
        Caption = #1054' '#1087#1088#1086#1075#1088#1072#1084#1084#1077
        OnClick = N2Click
      end
      object N12: TMenuItem
        Caption = #1055#1086#1084#1086#1097#1100
        OnClick = N12Click
      end
    end
  end
  object Timer1: TTimer
    Interval = 14
    OnTimer = Timer1Timer
    Left = 728
    Top = 464
  end
  object Timer2: TTimer
    Interval = 1500
    OnTimer = Timer2Timer
    Left = 728
    Top = 432
  end
  object OpenDialog1: TOpenDialog
    Left = 728
    Top = 400
  end
  object SaveDialog1: TSaveDialog
    Left = 728
    Top = 368
  end
  object ColorDialog1: TColorDialog
    Left = 728
    Top = 528
  end
end
