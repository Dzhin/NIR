//---------------------------------------------------------------------------

#ifndef ParametersLightSourseH
#define ParametersLightSourseH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TPLSForm : public TForm
{
__published:	// IDE-managed Components
	TLabel *Label1;
	TEdit *CPEdit;
	TButton *Button1;
	TButton *Button3;
	TStringGrid *CPStringGrid;
	TButton *Button2;
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall Button3Click(TObject *Sender);
	void __fastcall Button2Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TPLSForm(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TPLSForm *PLSForm;
//---------------------------------------------------------------------------
#endif
