//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TLabel *Label6;
	TLabel *Label13;
	TGroupBox *GroupBox1;
	TRadioButton *RadioButton13;
	TRadioButton *RadioButton1;
	TRadioButton *RadioButton2;
	TRadioButton *RadioButton3;
	TRadioButton *RadioButton4;
	TEdit *Edit1;
	TPanel *Panel1;
	TLabel *Label2;
	TLabel *Label3;
	TLabel *Label4;
	TLabel *Label5;
	TLabel *Label17;
	TEdit *Edit2;
	TEdit *Edit3;
	TEdit *Edit10;
	TUpDown *UpDown1;
	TEdit *Edit13;
	TUpDown *UpDown2;
	TPanel *Panel2;
	TLabel *Label8;
	TLabel *Label9;
	TLabel *Label10;
	TLabel *Label11;
	TLabel *Label12;
	TEdit *Edit6;
	TEdit *Edit7;
	TEdit *Edit8;
	TEdit *Edit9;
	TUpDown *UpDown3;
	TEdit *Edit15;
	TPanel *Panel4;
	TLabel *Label14;
	TLabel *Label15;
	TLabel *Label16;
	TUpDown *UpDown4;
	TUpDown *UpDown5;
	TUpDown *UpDown6;
	TEdit *Edit16;
	TEdit *Edit17;
	TEdit *Edit18;
	TGroupBox *GroupBox3;
	TRadioButton *RadioButton6;
	TRadioButton *RadioButton7;
	TRadioButton *RadioButton15;
	TGroupBox *GroupBox4;
	TRadioButton *RadioButton8;
	TRadioButton *RadioButton9;
	TGroupBox *GroupBox2;
	TLabel *Label7;
	TLabel *Label18;
	TLabel *Label19;
	TLabel *Label20;
	TEdit *Edit4;
	TEdit *Edit5;
	TEdit *Edit11;
	TEdit *Edit12;
	TUpDown *UpDown7;
	TUpDown *UpDown8;
	TUpDown *UpDown9;
	TUpDown *UpDown10;
	TEdit *Edit19;
	TEdit *Edit20;
	TEdit *Edit21;
	TEdit *Edit22;
	TEdit *Edit14;
	TRadioButton *RadioButton5;
	TRadioButton *RadioButton10;
	TRadioButton *RadioButton11;
	TRadioButton *RadioButton12;
	TLabel *Label21;
	void __fastcall UpDown1Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown2Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown3Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown4Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown5Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown6Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown7Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown8Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown9Click(TObject *Sender, TUDBtnType Button);
	void __fastcall UpDown10Click(TObject *Sender, TUDBtnType Button);
	void __fastcall Edit2Change(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
