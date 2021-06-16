//---------------------------------------------------------------------------


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
double pi=3.1415926535897932384;
struct decart
{
	int x,y;
};
struct polar
{
	int r,fi;
};

//Задание полином Цернике ------------------------------------------------------------------------------------------------------------------------------------------------------------------
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
double degree(double n, int m)//возведение в степень
{
	int i=0;
	double z=1;
	for (i = 0; i < m; i++) {
	   z=z*n;
	}
	return z;
}

/*double coefZernike (int m, int n, double p)// флешка
{
	int i;
	double R=0;
	for (i = 0; i <= (n-m)/2; i++) {
	   R=R+one1(i)*factorial(n-i)/(factorial((n-m)/2-i)*factorial((n+m)/2-i))*degree(p,n-2*i);
	}
	return R;
}*/
double fi(double x, double y)  //угол полярных координат
{
	if ((y==0)&&(x==0)) {return pi/4;}
	if (y==0) {return 0;}
	if (x==0) {return pi/2; }
	return atan(y/x);
}
double rad(double x,double y) //радиус-вектор полярных координат
{
	return sqrt((x)*(x)+(y)*(y));
}

double A13(double diam, int n)
{
   return 2*sqrt((n+1)/pi/diam);
}
 double polinomZernike ( int m, int n,  double diam, double x, double y, double amplitude)   //подсчет полиномов Цернике по Википедии  (нет)
 {
	 double R=0;
	 int s,j;

	 for (s=0; s <= (n-abs(m))/2; s++) {
		 R=R+one1(s)*factorial(n-s)/(factorial(s)*factorial((n+abs(m))/2-s)*factorial((n-abs(m))/2 - s))*degree(2*rad(x,y)/diam,n-2*s);
	 }
	 if (m>=0) {
		 return A13(diam,n)*R*cos(m*fi(x,y))*amplitude;
	 }
		 return A13(diam,n)*R*sin(m*fi(x,y))*amplitude;

 }

 double PC( int maxdiam, double x, double y, double amplitude)
 {
	  int count, i, j, k, l;
	  double FI=0;
//--------------------------Считываем коэффиценты полином из файла----------
	  ifstream fin("D:\\Yar\\FFT\\cellsarray.txt");
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
//---------------------------------------------------------------------------
	  double norma=0;
	  for (int i = 0; i < (int)count; i++) {
		 norma=norma+cellsarray[i][0]*cellsarray[i][0];
	  }
	  if (norma==0) { }else{for (int i = 0; i < (int)count; i++) {cellsarray[i][0]=cellsarray[i][0]/sqrt(norma);}}
	 for (int i = 0; i < (int)count; i++) {
		 FI=FI+cellsarray[i][0]*polinomZernike(cellsarray[i][2],cellsarray[i][1],(double)maxdiam,(double)(x),(double)(y),amplitude);
	 }
	  for (int i = 0; i < (int)count; i++)
	  delete cellsarray[i];
	 }

  return FI;
 }
 /*double polinomZernike ( int m, int n,  double diam, double x, double y, double amplitude)   //подсчет полиномов Цернике по Википедии
 {
	 double R=0;
	 int k,j;

	 for (k=0; k <= (n-m)/2; k++) {
		 R=R+one1(k)*factorial(n-k)/(factorial(k)*factorial((n+m)/2-k)*factorial((n-m)/2 - k))*degree(2*rad(x,y)/diam,n-2*k);
	 }
	 double Zmn=sqrt((n+1)/pi)*R*cos(fi(x,y));
	 return Zmn;

 } */
/*double polinomZernike ( int m, int n, double diam, double x, double y, double amplitude)   //подсчет полиномов Цернике по флешке
{
		return coefZernike(m,n,2*rad(x,y)/diam)*fi(x,y)*amplitude*A13(diam, n);
} */
//------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------



