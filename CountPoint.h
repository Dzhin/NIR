//---------------------------------------------------------------------------

#ifndef CountPointH
#define CountPointH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TCPForm : public TForm
{
__published:	// IDE-managed Components
	TEdit *CPEdit;
	TLabel *Label1;
	TStringGrid *CPStringGrid;
	TButton *Button1;
	TButton *Button2;
	TButton *Button3;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TCPForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TCPForm *CPForm;
//---------------------------------------------------------------------------
#endif
