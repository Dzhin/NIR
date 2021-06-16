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
double J0(double x);//������� ������� �������� �������
double J1(double x);//������� ������� ������� �������
double Jn(double x,int n);//������� ������� n-�� �������
double dJn(double x,int n,double d);//����������� ������� ������� n-�� �������
double Y0(double x);//������� ������� �������� �������
double Y1(double x);//������� ������� ������� �������
double Yn(double x,int n);//������� ������� n-�� �������
double dYn(double x,int n,double d);//����������� ������� ������� n-�� �������
complex<double> H1n(double x,int n);//������ ������� ������� n-�� �������
complex<double> dH1n(double x,int n,double d);//����������� ������ ������� ������� n-�� �������
complex<double> H2n(double x,int n);//������ ������� ������� n-�� �������
complex<double> dH2n(double x,int n,double d);//����������� ������ ������� ������� n-�� �������
complex<double> powc(complex<double> a, int n);
double Jn_i(double x,int n);
double Yn_i(double x,int n);
double Yn_1(double x,int n);
double sign(double x);//�������� �������
double pwn(double x,int n);//������������� �������
