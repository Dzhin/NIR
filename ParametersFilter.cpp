//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ParametersFilter.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm10 *Form10;
//---------------------------------------------------------------------------
__fastcall TForm10::TForm10(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button1Click(TObject *Sender)
{
	Form10->Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm10::Button2Click(TObject *Sender)
{
	Form10->Close();
}
//---------------------------------------------------------------------------

