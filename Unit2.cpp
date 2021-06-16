//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit2.h"
#include "Math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm2 *Form2;
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown1Click(TObject *Sender, TUDBtnType Button)
{
 Edit13->Text = IntToStr((int)pow((float)2,(float)UpDown1->Position));
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown2Click(TObject *Sender, TUDBtnType Button)
{
 Edit14->Text = IntToStr(UpDown2->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown3Click(TObject *Sender, TUDBtnType Button)
{
 Edit15->Text = IntToStr((int)pow((float)2,(float)UpDown3->Position));	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown4Click(TObject *Sender, TUDBtnType Button)
{
  Edit16->Text = IntToStr(UpDown4->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown5Click(TObject *Sender, TUDBtnType Button)
{
  Edit17->Text = IntToStr(UpDown5->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown6Click(TObject *Sender, TUDBtnType Button)
{
  Edit18->Text = IntToStr(UpDown6->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown7Click(TObject *Sender, TUDBtnType Button)
{
  Edit19->Text = IntToStr(UpDown7->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown8Click(TObject *Sender, TUDBtnType Button)
{
  Edit20->Text = IntToStr(UpDown8->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown9Click(TObject *Sender, TUDBtnType Button)
{
  Edit21->Text = IntToStr(UpDown9->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::UpDown10Click(TObject *Sender, TUDBtnType Button)
{
  Edit22->Text = IntToStr(UpDown10->Position);	
}
//---------------------------------------------------------------------------
void __fastcall TForm2::Edit2Change(TObject *Sender)
{
 float Kw = 2*M_PI/StrToFloat(Form2->Edit6->Text)*1E9;
 float freq = StrToFloat(Form2->Edit2->Text);
 float f;
 if (freq!=0)
 f = Kw/2/freq/freq;
 Label21->Caption = FloatToStrF(f,(TFloatFormat) 2,3,4);
}
//---------------------------------------------------------------------------

