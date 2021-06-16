object CPForm: TCPForm
  Left = 0
  Top = 0
  Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1090#1086#1095#1077#1082
  ClientHeight = 413
  ClientWidth = 587
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
    Left = 8
    Top = 0
    Width = 93
    Height = 13
    Caption = #1050#1086#1083#1080#1095#1077#1089#1090#1074#1086' '#1090#1086#1095#1077#1082
  end
  object CPEdit: TEdit
    Left = 8
    Top = 16
    Width = 121
    Height = 21
    TabOrder = 0
    Text = '2'
  end
  object CPStringGrid: TStringGrid
    Left = 8
    Top = 80
    Width = 513
    Height = 281
    Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine, goRangeSelect, goEditing]
    TabOrder = 1
    Visible = False
    ColWidths = (
      64
      64
      64
      64
      64)
  end
  object Button1: TButton
    Left = 8
    Top = 43
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 2
    OnClick = Button1Click
  end
  object Button2: TButton
    Left = 8
    Top = 367
    Width = 75
    Height = 25
    Caption = 'OK'
    TabOrder = 3
    Visible = False
    OnClick = Button2Click
  end
  object Button3: TButton
    Left = 120
    Top = 43
    Width = 75
    Height = 25
    Caption = #1054#1090#1084#1077#1085#1072
    TabOrder = 4
    OnClick = Button3Click
  end
end
