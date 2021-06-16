//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
/*Form3->Height = StrToInt(Form2->Edit21->Text);
Form3->Width = 700;
Form3->Image1->Height = Form3->Height-60;
Form3->Image1->Width = Form3->Width-30;*/
}
//---------------------------------------------------------------------------
void __fastcall TForm3::FormCanResize(TObject *Sender, int &NewWidth,
      int &NewHeight, bool &Resize)
{
/* Form3->Image1->Height = Form3->Height-30;
 Form3->Image1->Width = Form3->Width-45;
 Form1->N14Click(Sender);*/
}
//---------------------------------------------------------------------------
