//---------------------------------------------------------------------------

#ifndef SpecFunctionH
#define SpecFunctionH
//---------------------------------------------------------------------------
#include "complex.h"
using namespace std;

#endif

double f0(double x);
double f1(double x);
double Teta0(double x);
double Teta1(double x);
double J0(double x);//Функция Бесселя нулевого порядка
double J1(double x);//Функция Бесселя первого порядка
double Jn(double x,int n);//Функция Бесселя n-го порядка
double dJn(double x,int n,double d);//Производная функции Бесселя n-го порядка
double Y0(double x);//Функция Неймана нулевого порядка
double Y1(double x);//Функция Неймана первого порядка
double Yn(double x,int n);//Функция Неймана n-го порядка
double dYn(double x,int n,double d);//Производная функции Неймана n-го порядка
complex<double> H1n(double x,int n);//Первая функция Ханкеля n-го порядка
complex<double> dH1n(double x,int n,double d);//Производная первой функция Ханкеля n-го порядка
complex<double> H2n(double x,int n);//Вторая функция Ханкеля n-го порядка
complex<double> dH2n(double x,int n,double d);//Производная первой функция Ханкеля n-го порядка
complex<double> powc(complex<double> a, int n);
double Jn_i(double x,int n);
double Yn_i(double x,int n);
double Yn_1(double x,int n);
double sign(double x);//Знаковая функция
double pwn(double x,int n);//Целочисленная степень
