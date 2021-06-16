//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "ParametersLightSourse.h"
#include <fstream>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TPLSForm *PLSForm;
//---------------------------------------------------------------------------
__fastcall TPLSForm::TPLSForm(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TPLSForm::Button1Click(TObject *Sender)
{
	int countCol = 7;
	CPStringGrid->Options = CPStringGrid->Options << goEditing;
	PLSForm->CPStringGrid->Visible="true";
	PLSForm->Button2->Visible="true";
	int count=StrToInt(PLSForm->CPEdit->Text);
	PLSForm->CPStringGrid->ColCount=countCol;
	PLSForm->CPStringGrid->RowCount=count+1;
	PLSForm->CPStringGrid->FixedCols=0;
	PLSForm->CPStringGrid->FixedRows=1;
	PLSForm->CPStringGrid->Cells[0][0]="№";
	PLSForm->CPStringGrid->Cells[1][0]="x";
	PLSForm->CPStringGrid->Cells[2][0]="y";
	PLSForm->CPStringGrid->Cells[3][0]="r";
	PLSForm->CPStringGrid->Cells[4][0]="коэффициент мощности";
	PLSForm->CPStringGrid->Cells[5][0]="сигма";
	PLSForm->CPStringGrid->Cells[6][0]="фи";

	for (int i = 1; i < countCol; i++) {
		for (int j = 1; j < count+2; j++) {
			PLSForm->CPStringGrid->Cells[i][j]="0";
		}
	}
	for (int j = 1; j < count+2; j++) {
		PLSForm->CPStringGrid->Cells[3][j]="10";
	}
		for (int j = 1; j < count+2; j++) {
		PLSForm->CPStringGrid->Cells[4][j]="1";
	}
	for (int j = 1; j < count+2; j++) {
		PLSForm->CPStringGrid->Cells[5][j]="100";
	}
//	for (int j = 1; j < count+2; j++) {
//		CPForm->CPStringGrid->Cells[5][j]="100";
//	}
	for(int j=1; j < count+2;j++)
	{
		PLSForm->CPStringGrid->Cells[0][j]=j;
	}
}


//---------------------------------------------------------------------------
void __fastcall TPLSForm::Button3Click(TObject *Sender)
{
	PLSForm->Close();	
}
//---------------------------------------------------------------------------
void __fastcall TPLSForm::Button2Click(TObject *Sender)
{
	int i,j,countRow=StrToInt(PLSForm->CPStringGrid->RowCount);
	int countCol=StrToInt(PLSForm->CPStringGrid->ColCount);

	ofstream fout;
	AnsiString path = ExtractFilePath(Application->ExeName)+"ParameterPoint.txt";
	fout.open(path.c_str());
	fout << PLSForm->CPStringGrid->RowCount-1<<"\n"; //пишем строки
	fout << PLSForm->CPStringGrid->ColCount-1<<"\n"; //пишем столбцы

	for (j = 1; j < countRow; j++) {
		fout << "\n";
		for (i = 1; i < countCol; i++) {
			fout <<  StrToFloat(PLSForm->CPStringGrid->Cells[i][j]) << " ";
		}
	}
	fout.close();
	PLSForm->Close();
}
//---------------------------------------------------------------------------
