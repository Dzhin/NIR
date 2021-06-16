object Form2: TForm2
  Left = 0
  Top = 0
  Caption = 'Form2'
  ClientHeight = 395
  ClientWidth = 642
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
    Top = 8
    Width = 107
    Height = 13
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1101#1083#1077#1084#1077#1085#1090#1072
  end
  object Label6: TLabel
    Left = 224
    Top = 8
    Width = 139
    Height = 13
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1084#1086#1076#1077#1083#1080#1088#1086#1074#1072#1085#1080#1103
  end
  object Label13: TLabel
    Left = 432
    Top = 8
    Width = 113
    Height = 13
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1080#1079#1084#1077#1088#1077#1085#1080#1103
  end
  object GroupBox1: TGroupBox
    Left = 8
    Top = 232
    Width = 193
    Height = 155
    Caption = #1042#1080#1076' '#1082#1086#1076#1080#1088#1086#1074#1082#1080
    TabOrder = 0
    object RadioButton13: TRadioButton
      Left = 8
      Top = 16
      Width = 113
      Height = 17
      Caption = #1053#1077#1082#1086#1076#1080#1088#1086#1074#1072#1085#1085#1099#1081
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton1: TRadioButton
      Left = 8
      Top = 40
      Width = 113
      Height = 17
      Caption = #1051#1080#1085#1077#1081#1085#1072#1103
      TabOrder = 1
    end
    object RadioButton2: TRadioButton
      Left = 8
      Top = 64
      Width = 113
      Height = 17
      Caption = #1056#1072#1076#1080#1072#1083#1100#1085#1072#1103
      TabOrder = 2
    end
    object RadioButton3: TRadioButton
      Left = 8
      Top = 88
      Width = 175
      Height = 17
      Caption = #1050#1074#1072#1076#1088#1072#1090#1080#1095#1085#1072#1103' '#1086#1088#1086#1080#1076#1072#1083#1100#1085#1072#1103' '
      TabOrder = 3
    end
    object RadioButton4: TRadioButton
      Left = 8
      Top = 112
      Width = 153
      Height = 17
      Caption = #1050#1074#1072#1076#1088#1072#1090#1080#1095#1085#1072#1103' '#1088#1072#1076#1080#1072#1083#1100#1085#1072#1103
      TabOrder = 4
    end
    object Edit1: TEdit
      Left = 96
      Top = -176
      Width = 121
      Height = 21
      TabOrder = 5
      Text = 'Edit1'
    end
    object RadioButton10: TRadioButton
      Left = 10
      Top = 135
      Width = 113
      Height = 17
      Caption = #1084#1085#1086#1075#1086#1087#1086#1088#1103#1076#1082#1086#1074#1072#1103
      TabOrder = 6
    end
  end
  object Panel1: TPanel
    Left = 8
    Top = 32
    Width = 193
    Height = 185
    TabOrder = 1
    object Label2: TLabel
      Left = 8
      Top = 16
      Width = 64
      Height = 13
      Caption = #1056#1072#1079#1084#1077#1088#1085#1086#1089#1090#1100
    end
    object Label3: TLabel
      Left = 8
      Top = 48
      Width = 109
      Height = 13
      Caption = #1053#1086#1084#1077#1088' '#1089#1080#1085#1075#1091#1083#1103#1088#1085#1086#1089#1090#1080
    end
    object Label4: TLabel
      Left = 8
      Top = 80
      Width = 95
      Height = 13
      Caption = #1063#1072#1089#1090#1086#1090#1072' '#1082#1086#1076'. (1/'#1084')'
    end
    object Label5: TLabel
      Left = 8
      Top = 112
      Width = 113
      Height = 13
      Caption = #1055#1072#1088#1072#1084#1077#1090#1088' HG '#1092#1091#1085#1082#1094#1080#1080
    end
    object Label17: TLabel
      Left = 8
      Top = 152
      Width = 115
      Height = 13
      Caption = #1060#1080#1079#1080#1095#1077#1089#1082#1080#1081' '#1088#1072#1079#1084#1077#1088' ('#1084')'
    end
    object Label21: TLabel
      Left = 156
      Top = 80
      Width = 30
      Height = 13
      Caption = '0'
    end
    object Edit2: TEdit
      Left = 109
      Top = 75
      Width = 41
      Height = 21
      TabOrder = 0
      Text = '10000'
      OnChange = Edit2Change
    end
    object Edit3: TEdit
      Left = 128
      Top = 112
      Width = 57
      Height = 21
      TabOrder = 2
      Text = '1,5'
    end
    object Edit10: TEdit
      Left = 136
      Top = 152
      Width = 49
      Height = 21
      TabOrder = 1
      Text = '0,005'
    end
    object UpDown1: TUpDown
      Left = 167
      Top = 10
      Width = 16
      Height = 24
      Position = 9
      TabOrder = 3
      OnClick = UpDown1Click
    end
    object Edit13: TEdit
      Left = 82
      Top = 13
      Width = 87
      Height = 21
      TabOrder = 4
      Text = '512'
    end
    object UpDown2: TUpDown
      Left = 167
      Top = 45
      Width = 16
      Height = 24
      TabOrder = 5
      OnClick = UpDown2Click
    end
  end
  object Panel2: TPanel
    Left = 216
    Top = 32
    Width = 201
    Height = 185
    TabOrder = 2
    object Label8: TLabel
      Left = 8
      Top = 16
      Width = 85
      Height = 13
      Caption = #1056#1072#1089#1096#1080#1088#1077#1085#1080#1077' '#1041#1055#1060
    end
    object Label9: TLabel
      Left = 8
      Top = 48
      Width = 90
      Height = 13
      Caption = #1044#1083#1080#1085#1072' '#1074#1086#1083#1085#1099' ('#1085#1084')'
    end
    object Label10: TLabel
      Left = 8
      Top = 80
      Width = 75
      Height = 13
      Caption = #1056#1072#1089#1089#1090#1086#1103#1085#1080#1077' ('#1084')'
    end
    object Label11: TLabel
      Left = 8
      Top = 112
      Width = 123
      Height = 13
      Caption = #1056#1072#1079#1084#1077#1088' '#1074#1099#1088#1077#1079#1072' '#1074' '#1094#1077#1085#1090#1088#1077
    end
    object Label12: TLabel
      Left = 8
      Top = 152
      Width = 145
      Height = 13
      Caption = #1056#1072#1076#1080#1091#1089' '#1075#1072#1091#1089#1089#1086#1074#1086#1075#1086' '#1087#1091#1095#1082#1072' ('#1084')'
    end
    object Edit6: TEdit
      Left = 104
      Top = 48
      Width = 89
      Height = 21
      TabOrder = 0
      Text = '532'
    end
    object Edit7: TEdit
      Left = 88
      Top = 80
      Width = 105
      Height = 21
      TabOrder = 1
      Text = '1,0'
    end
    object Edit8: TEdit
      Left = 144
      Top = 112
      Width = 49
      Height = 21
      TabOrder = 2
      Text = '0'
    end
    object Edit9: TEdit
      Left = 160
      Top = 152
      Width = 33
      Height = 21
      TabOrder = 3
      Text = '0,002'
    end
    object UpDown3: TUpDown
      Left = 176
      Top = 10
      Width = 16
      Height = 24
      TabOrder = 4
      OnClick = UpDown3Click
    end
    object Edit15: TEdit
      Left = 105
      Top = 13
      Width = 72
      Height = 21
      TabOrder = 5
      Text = '1'
    end
  end
  object Panel4: TPanel
    Left = 436
    Top = 27
    Width = 201
    Height = 113
    TabOrder = 3
    object Label14: TLabel
      Left = 8
      Top = 16
      Width = 134
      Height = 13
      Caption = #1053#1086#1084#1077#1088' '#1089#1090#1088#1086#1082#1080' '#1080#1083#1080' '#1089#1090#1086#1083#1073#1094#1072
    end
    object Label15: TLabel
      Left = 8
      Top = 48
      Width = 81
      Height = 13
      Caption = #1053#1072#1095#1072#1083#1086' '#1089#1077#1095#1077#1085#1080#1103
    end
    object Label16: TLabel
      Left = 8
      Top = 80
      Width = 75
      Height = 13
      Caption = #1050#1086#1085#1077#1094' '#1089#1077#1095#1077#1085#1080#1103
    end
    object UpDown4: TUpDown
      Left = 176
      Top = 12
      Width = 16
      Height = 24
      Max = 32000
      Position = 512
      TabOrder = 0
      OnClick = UpDown4Click
    end
    object UpDown5: TUpDown
      Left = 176
      Top = 45
      Width = 16
      Height = 24
      Max = 32000
      TabOrder = 1
      OnClick = UpDown5Click
    end
    object UpDown6: TUpDown
      Left = 176
      Top = 75
      Width = 16
      Height = 24
      Max = 32000
      Position = 511
      TabOrder = 2
      OnClick = UpDown6Click
    end
    object Edit16: TEdit
      Left = 151
      Top = 13
      Width = 27
      Height = 21
      TabOrder = 3
      Text = '512'
    end
    object Edit17: TEdit
      Left = 120
      Top = 45
      Width = 57
      Height = 21
      TabOrder = 4
      Text = '0'
    end
    object Edit18: TEdit
      Left = 120
      Top = 75
      Width = 57
      Height = 21
      TabOrder = 5
      Text = '511'
    end
  end
  object GroupBox3: TGroupBox
    Left = 216
    Top = 232
    Width = 201
    Height = 111
    Caption = #1042#1080#1076' '#1089#1074#1077#1090#1086#1074#1086#1075#1086' '#1087#1091#1095#1082#1072
    TabOrder = 4
    object RadioButton6: TRadioButton
      Left = 8
      Top = 16
      Width = 113
      Height = 17
      Caption = #1055#1083#1086#1089#1082#1080#1081
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton7: TRadioButton
      Left = 8
      Top = 40
      Width = 113
      Height = 17
      Caption = #1043#1072#1091#1089#1089#1086#1074
      TabOrder = 1
    end
    object RadioButton15: TRadioButton
      Left = 8
      Top = 64
      Width = 153
      Height = 17
      Caption = #1055#1088#1086#1080#1079#1074#1086#1083#1100#1085#1099#1081' ('#1080#1079' '#1092#1072#1081#1083#1072')'
      TabOrder = 2
    end
    object RadioButton11: TRadioButton
      Left = 9
      Top = 87
      Width = 113
      Height = 17
      Caption = #1056#1072#1089#1093#1086#1076#1103#1097#1080#1081#1089#1103
      TabOrder = 3
    end
  end
  object GroupBox4: TGroupBox
    Left = 432
    Top = 160
    Width = 201
    Height = 65
    Caption = #1042#1080#1076' '#1089#1077#1095#1077#1085#1080#1103
    TabOrder = 5
    object RadioButton8: TRadioButton
      Left = 8
      Top = 16
      Width = 113
      Height = 17
      Caption = #1043#1086#1088#1080#1079#1086#1085#1090#1072#1083#1100#1085#1086#1077
      Checked = True
      TabOrder = 0
      TabStop = True
    end
    object RadioButton9: TRadioButton
      Left = 8
      Top = 40
      Width = 113
      Height = 17
      Caption = #1042#1077#1088#1090#1080#1082#1072#1083#1100#1085#1086#1077
      TabOrder = 1
    end
    object RadioButton5: TRadioButton
      Left = 112
      Top = 17
      Width = 113
      Height = 17
      Caption = #1056#1072#1076#1080#1072#1083#1100#1085#1086#1077
      TabOrder = 2
    end
    object RadioButton12: TRadioButton
      Left = 112
      Top = 40
      Width = 113
      Height = 17
      Caption = #1059#1075#1083#1086#1074#1086#1077
      TabOrder = 3
    end
  end
  object GroupBox2: TGroupBox
    Left = 436
    Top = 242
    Width = 201
    Height = 153
    Caption = #1055#1072#1088#1072#1084#1077#1090#1088#1099' '#1074#1099#1074#1086#1076#1072
    TabOrder = 6
    object Label7: TLabel
      Left = 8
      Top = 16
      Width = 95
      Height = 13
      Caption = #1063#1080#1089#1083#1086' '#1076#1077#1083#1077#1085#1080#1081' X,Y'
    end
    object Label18: TLabel
      Left = 8
      Top = 48
      Width = 68
      Height = 13
      Caption = #1044#1080#1072#1087#1072#1079#1086#1085' a,b'
    end
    object Label19: TLabel
      Left = 8
      Top = 80
      Width = 62
      Height = 13
      Caption = #1055#1086#1076#1087#1080#1089#1080' X,Y'
    end
    object Label20: TLabel
      Left = 8
      Top = 112
      Width = 81
      Height = 13
      Caption = #1056#1072#1079#1084#1077#1088' '#1086#1082#1085#1072' X,Y'
    end
    object Edit4: TEdit
      Left = 96
      Top = 48
      Width = 49
      Height = 21
      TabOrder = 1
      Text = '0'
    end
    object Edit5: TEdit
      Left = 144
      Top = 48
      Width = 49
      Height = 21
      TabOrder = 3
      Text = '1'
    end
    object Edit11: TEdit
      Left = 96
      Top = 80
      Width = 49
      Height = 21
      TabOrder = 0
      Text = #1084#1084
    end
    object Edit12: TEdit
      Left = 144
      Top = 80
      Width = 49
      Height = 21
      TabOrder = 2
      Text = #1042#1090'/'#1084
    end
    object UpDown7: TUpDown
      Left = 136
      Top = 18
      Width = 16
      Height = 24
      Min = 1
      Position = 1
      TabOrder = 4
      OnClick = UpDown7Click
    end
    object UpDown8: TUpDown
      Left = 174
      Top = 18
      Width = 16
      Height = 24
      Min = 1
      Position = 1
      TabOrder = 5
      OnClick = UpDown8Click
    end
    object UpDown9: TUpDown
      Left = 128
      Top = 107
      Width = 16
      Height = 24
      Min = 1
      Max = 32000
      Position = 1000
      TabOrder = 6
      OnClick = UpDown9Click
    end
    object UpDown10: TUpDown
      Left = 176
      Top = 107
      Width = 16
      Height = 24
      Min = 1
      Max = 32000
      Position = 700
      TabOrder = 7
      OnClick = UpDown10Click
    end
    object Edit19: TEdit
      Left = 111
      Top = 21
      Width = 27
      Height = 21
      TabOrder = 8
      Text = '1'
    end
    object Edit20: TEdit
      Left = 151
      Top = 21
      Width = 26
      Height = 21
      TabOrder = 9
      Text = '1'
    end
    object Edit21: TEdit
      Left = 97
      Top = 107
      Width = 33
      Height = 21
      TabOrder = 10
      Text = '1000'
    end
    object Edit22: TEdit
      Left = 145
      Top = 107
      Width = 33
      Height = 21
      TabOrder = 11
      Text = '700'
    end
  end
  object Edit14: TEdit
    Left = 131
    Top = 80
    Width = 43
    Height = 21
    TabOrder = 7
    Text = '0'
  end
end
