object PLSForm: TPLSForm
  Left = 0
  Top = 0
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1080#1089#1090#1086#1095#1085#1080#1082#1086#1074' '#1089#1074#1077#1090#1072
  ClientHeight = 421
  ClientWidth = 670
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  PixelsPerInch = 96
  TextHeight = 13
  object Label1: TLabel
    Left = 16
    Top = 8
    Width = 93
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1090#1086#1095#1077#1082
  end
  object CPEdit: TEdit
    Left = 16
    Top = 24
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '2'
  end
  object Button1: TButton
    Left = 16
    Top = 51
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 1
    OnClick = Button1Click
  end
  object Button3: TButton
    Left = 128
    Top = 51
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 2
    OnClick = Button3Click
  end
  object CPStringGrid: TStringGrid
    Left = 16
    Top = 82
    Width = 513
    Height = 281
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 3
    Visible = False
    ColWidths = (
      64
      64
      64
      64
      64)
  end
  object Button2: TButton
    Left = 16
    Top = 378
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 4
    Visible = False
    OnClick = Button2Click
  end
end
