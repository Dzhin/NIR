//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------------
USEFORM("Forma.cpp", Form1);
USEFORM("ForMenyu1.cpp", Form8);
USEFORM("Unit9.cpp", Form9);
USEFORM("FormForGrafics.cpp", GF10);
USEFORM("CountPoint.cpp", CPForm);
USEFORM("ParametersLightSourse.cpp", PLSForm);
USEFORM("ParametersFilter.cpp", Form10);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	try
	{
		Application->Initialize();
		Application->CreateForm(__classid(TForm1), &Form1);
		Application->CreateForm(__classid(TForm8), &Form8);
		Application->CreateForm(__classid(TForm9), &Form9);
		Application->CreateForm(__classid(TGF10), &GF10);
		Application->CreateForm(__classid(TCPForm), &CPForm);
		Application->CreateForm(__classid(TPLSForm), &PLSForm);
		Application->CreateForm(__classid(TForm10), &Form10);
		Application->Run();
	}
	catch (Exception &exception)
	{
		Application->ShowException(&exception);
	}
	catch (...)
	{
		try
		{
			throw Exception("");
		}
		catch (Exception &exception)
		{
			Application->ShowException(&exception);
		}
	}
	return 0;
}
//---------------------------------------------------------------------------
