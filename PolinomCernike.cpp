//---------------------------------------------------------------------------


#pragma hdrstop

#include "PolinomCernike.h"
#pragma hdrstop
#include "Unit9.h"
#include "Translate.h"
#include <fstream>
#include "Forma.h"
#include "Imagebase.h"
#include "bmpfile.h"
#include "anyfile.h"
#include "memory.h"
#include "fill.h"
//---------------------------------------------------------------------------

#pragma package(smart_init)
int one1(int n)   //возведение -1 в степень
{
	if (n%2==0) { return 1;} else {return -1;}
}
int factorial(int p)
{
	if (p==0) {  return 1;}
	else{
	int i, f=1;
	for (i = 1; i <= p; i++) {
	  f=f*i;
	}
	return f;
	}
}
double degree(double n, int m)//возведение в целую степень
{
	int i=0;
	double z=1;
	for (i = 0; i < m; i++) {
	   z=z*n;
	}
	return z;
}
double fi(int x, int y)  //угол полярных координат
{
	double pi=3.1415926535897932384;
	if ((y==0)&&(x==0)) {return pi/4;}
	if (y==0) {return 0;}
	if (x==0) {return pi/2; }
	return atan((double)y/(double)x);
}



//---------------------------------------------------------------------------
int CraftAberation(int b,unsigned char *filenameAmplitude,unsigned char *filenamePhase, int r0){
const int N=256;
double pi=3.1415926535897932384;
int count,i,j,p,n,m,x,y;
int X=256;
int Y=256;
double alfa=StrToFloat(Form1->Edit4->Text);
int size=StrToInt(Form1->Edit3->Text)/*увеличение*/;
float Anm,R,r,r1=N/2,f,a;
complex<float>im(0,1),FI;
int k,height=StrToInt(Form1->Edit1->Text)/*высота*/,widht=StrToInt(Form1->Edit2->Text)/*длинна*/ ;
//--------------------------Считываем коэффиценты полином из файла----------
	  ifstream fin("D:\\cellsarray.txt");
	  if (!fin.is_open())
	  { // если файл не открыт
		Form9->Show();
		Form9->Label1->Caption="Не могу открыть файл";
	  }
	else
	{
	  fin >> count;
	  double **cellsarray = new double* [count];
	  for (int i = 0; i < (int)count; i++)
	  cellsarray[i] = new double [3];
	  for (int i = 0; i < (int)count; i++) {
		  for (int j = 0; j < 3; j++) {
			  fin >> cellsarray [i][j];
		  }
	  }
	  fin.close();

//--------------------------Нормируем коэффиценты----------------------------
double norma=0;
	  for (int i = 0; i < (int)count; i++) {
		 norma=norma+cellsarray[i][0]*cellsarray[i][0];
	  }
	  if (norma==0) { }else{for (int i = 0; i < (int)count; i++) {cellsarray[i][0]=cellsarray[i][0]/sqrt(norma);}}
			/*  Form1->Label1->Caption=FloatToStr(cellsarray[0][0]);
	  Form1->Label2->Caption=FloatToStr(cellsarray[0][1]);
	  Form1->Label3->Caption=IntToStr(count);              */
//---------------------------------------------------------------------------

//ReadBMPFile("Wave.bmp",X,Y);//Чтение заголовка BMP файла
X=256;
Y=256;
ImageBase IB(X,Y);
ImageBase IB1(X,Y);
//Form1->Label3->Caption=IntToStr(X);
/*IB.ReadFile(filenamePhase);//Чтение фазы из файла
IB1.ReadFileA(filenameAmplitude);//Чтение амплитуды из файла
for (x = 0; x < N; x++)
	{
	for (y = 0; y < N; y++)
		{
			IB.ImageComplex[x][y]=polar(abs(IB1.ImageComplex[x][y]),arg(IB.ImageComplex[x][y]));
		}
	} */
   /*	for(x=0;x<N;x++)
	   {
		for(y=0;y<N;y++)
		   {
			 if ((pow((float)(2*x-X),2))/pow((float)height,2)+(pow((float)(2*y-X),2))/pow((float)widht,2)<=1)
			 {

			 //IB.ImageComplex[i][j]=polar((float)cos(alfa*sqrt(double((i-N/2)*(i-N/2)+(j-N/2)*(j-N/2)))),(float)0.);
				if (Form1->RadioButton1->Checked==true){
					if (cos(alfa*y)>0) {k=0;}else{k=M_PI;}
					IB1.ImageComplex[x][y]=polar((float)abs(cos(alfa*y)),(float)k);
					}
				else
				if  (Form1->RadioButton2->Checked==true){
					if (sin(alfa*y)>0) {k=0;}else{k=M_PI;}
					IB1.ImageComplex[x][y]=polar((float)abs(sin(alfa*y)),(float)k);
					}
				else
					IB1.ImageComplex[x][y]=polar((float)1.,(float)0.);
			 }
			else{IB1.ImageComplex[x][y]=polar((float)0.,(float)0.); }
			}

	   }
	   IB1.ViewImageComplex(Form1->Image5,1,1,1);
	   IB1.ViewImageComplex(Form1->Image6,2,1,1); */
//complex<float> ImageComplex[N][N];
//Form1->Label2->Caption=FloatToStr(abs(IB.ImageComplex[127][128]));

float R1,R2,R3;
for (x = 0; x < N; x++)
	{
	for (y = 0; y < N; y++)
		{
		r=sqrt((float)((x-N/2)*(x-N/2)+(y-N/2)*(y-N/2)));
		if (r/r0<=1)
			{
			FI=0;
			for (i=0; i < (int)count; i++)
				{
				a=(int)cellsarray[i][0];
				n=(int)cellsarray[i][1];
				m=(int)cellsarray[i][2];
				//f=atan2(y-N/2,x-N/2+0.0000000000000001);
			if(atan2(y-N/2,x-N/2+0.0000001)>0)
			{
			f=atan2(y-N/2,x-N/2+0.0000001);
			}
		else
			{
			f=atan2(y-N/2,x-N/2+0.0000001)+2*M_PI;
			}
				//f=fi(x-N/2, y-N/2);
				Anm=sqrt((n+1)/pi/r0/r0);
				R=0;
				for (p = 0; p <= (n-abs(m))/2; p++)
					{
					R1=one1(p)*factorial(n-p);
					R2=factorial(p)*factorial((n+m)/2-p)*factorial((n-m)/2-p);
					R3=degree(r/r0,n-2*p);
					R=R+R3/R2*R1;
					//R=R+one1(p)*factorial(n-p)/(factorial(p)*factorial(n+m/2-p)*factorial(n-m/2-p))*pow(r*2/N,n-2*p);
					}

				//if (m==0) {k=1;} else{k=m;}


				FI+=polar(a*Anm*R,m*f); //Подсчет полиномов Цернике
				}



			IB.ImageComplex[x][y]=polar(abs(FI)*abs(IB1.ImageComplex[x][y]),arg(FI)+arg(IB1.ImageComplex[x][y]));
			//IB1.ImageComplex[x][y]=polar(abs(FI),arg(FI));
			}
		else
			{
			IB.ImageComplex[x][y]=polar((float)0.,(float)0.);
			//IB1.ImageComplex[x][y]=polar((float)0.,(float)0.);
			}
		}
	}
//Form1->Label1->Caption=FloatToStr(abs(FI));
IB.ViewImageComplex(Form1->Image1,1,1,1);
IB.ViewImageComplex(Form1->Image2,2,1,1);
IB.Zeros = size;
IB.fft(1);
IB.Zeros = size;
IB.ViewImageComplex(Form1->Image3,1,1,1);
IB.ViewImageComplex(Form1->Image4,2,1,1);

}
return 1;
}
//---------------------------------------------------------------------------
