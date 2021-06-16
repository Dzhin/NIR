//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "CountPoint.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TCPForm *CPForm;
//---------------------------------------------------------------------------
__fastcall TCPForm::TCPForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TCPForm::Button1Click(TObject *Sender)
{
	int countCol = 6;
	CPStringGrid->Options = CPStringGrid->Options << goEditing;
	CPForm->CPStringGrid->Visible="true";
	CPForm->Button2->Visible="true";
	int count=StrToInt(CPForm->CPEdit->Text);
	CPForm->CPStringGrid->ColCount=countCol;
	CPForm->CPStringGrid->RowCount=count+1;
	CPForm->CPStringGrid->FixedCols=0;
	CPForm->CPStringGrid->FixedRows=1;
	CPForm->CPStringGrid->Cells[0][0]="№";
	CPForm->CPStringGrid->Cells[1][0]="альфа";
	CPForm->CPStringGrid->Cells[2][0]="бетта";
	CPForm->CPStringGrid->Cells[3][0]="коэффициент мощности";
	CPForm->CPStringGrid->Cells[4][0]="сигма";
	CPForm->CPStringGrid->Cells[5][0]="фи";

	for (int i = 1; i < countCol; i++) {
		for (int j = 1; j < count+2; j++) {
			CPForm->CPStringGrid->Cells[i][j]="0";
		}
	}
	for (int j = 1; j < count+2; j++) {
		CPForm->CPStringGrid->Cells[3][j]="1";
	}
	for (int j = 1; j < count+2; j++) {
		CPForm->CPStringGrid->Cells[4][j]="100";
	}
//	for (int j = 1; j < count+2; j++) {
//		CPForm->CPStringGrid->Cells[5][j]="100";
//	}
	for(int j=1; j < count+2;j++)
	{
		CPForm->CPStringGrid->Cells[0][j]=j;
	}
}


//---------------------------------------------------------------------------
void __fastcall TCPForm::Button2Click(TObject *Sender)
{
	int i,j,countRow=StrToInt(CPForm->CPStringGrid->RowCount);
	int countCol=StrToInt(CPForm->CPStringGrid->ColCount);

	ofstream fout;
	AnsiString path = ExtractFilePath(Application->ExeName)+"ParameterPoint.txt";
	fout.open(path.c_str());
	fout << CPForm->CPStringGrid->RowCount-1<<"\n"; //пишем строки
	fout << CPForm->CPStringGrid->ColCount-1<<"\n"; //пишем столбцы

	for (j = 1; j < countRow; j++) {
		fout << "\n";
		for (i = 1; i < countCol; i++) {
			fout <<  StrToFloat(CPForm->CPStringGrid->Cells[i][j]) << " ";
		}
	}
	fout.close();
	CPForm->Close();
}


//---------------------------------------------------------------------------

void __fastcall TCPForm::Button3Click(TObject *Sender)
{
	CPForm->Close();	
}
//---------------------------------------------------------------------------

