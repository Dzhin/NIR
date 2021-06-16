//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "SpecFunction.h"
#include "math.h"

//---------------------------------------------------------------------------

#pragma package(smart_init)
double f0(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x3 = x2*x/3;
 x4 = x2*x2;
 x5 = x3*x3;
 x6 = x4*x2;
 f = 0.79788456-0.00000077/x*3-0.00552740/x2-0.00009512/x3+
     0.00137237/x4-0.00072805/x5+0.00014476/x6;
 return(f);
}
double f1(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x3 = x2*x/3;
 x4 = x2*x2;
 x5 = x3*x3;
 x6 = x4*x2;
 f = 0.79788456+0.00000156/x*3+0.01659667/x2+0.00017105/x3-
     0.00249511/x4+0.00113653/x5-0.00020033/x6;
 return(f);
}
double Teta0(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x3 = x2*x/3;
 x4 = x2*x2;
 x5 = x3*x3;
 x6 = x4*x2;
 f = x-0.78539816-0.04166397/x*3-0.00003954/x2+0.00262573/x3-0.00054125/x4-
       0.00029333/x5+0.00013558/x6;
 return(f);
}
double Teta1(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x3 = x2*x/3;
 x4 = x2*x2;
 x5 = x3*x3;
 x6 = x4*x2;
 f = x-2.35619449+0.12499612/x*3+0.00005650/x2-0.00637879/x3+0.00074348/x4+
     0.00079824/x5-0.00029166/x6;
 return(f);
}
double J0(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x4 = x2*x2;
 x6 = x4*x2;
 x8 = x4*x4;
 x10 = x8*x2;
 x12 = x10*x2;
 if((x<3) && (x>-3))
    f = 1-2.2499997*x2+1.2656208*x4-0.3163866*x6+0.0444479*x8-
          0.0039444*x10+0.0002100*x12;
 else
    if(x>3)
      f = 1/sqrt(x)*f0(x)*cos(Teta0(x));
    else
      f = 1;
return(f);
}
double J1(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x4 = x2*x2;
 x6 = x4*x2;
 x8 = x4*x4;
 x10 = x8*x2;
 x12 = x10*x2;
 if((x<3) && (x>-3))
    f = 0.5*x-0.56249985*x2*x+0.21093573*x4*x-0.03954289*x6*x+
        0.00443319*x8*x-0.00031761*x10*x+0.00001109*x12*x;
 else
    if(x>3)
      f = 1/sqrt(x)*f1(x)*cos(Teta1(x));
    else
      f = 0;
return(f);
}
double Jn_i(double x,int n)
{
 int i,m;
 double fn,fn1,f;
 m = n;
 n = abs(n);
 switch(n)
        {
         case 0:
                f = J0(x);
                break;
         case 1:
                f = J1(x);
                break;
         default:
                fn = J1(x);
                fn1 = J0(x);
                for(i=2;i<=n;i++)
                   if(x!=0)
                     {
                      f = (fn*2*(i-1)-fn1*x)/x;
                      fn1 = fn;
                      fn = f;
                     }
                   else
                     f = 0;
                break;
         }
 if(m<0)
 if(n%2==1)
   f = f*(-1);
 return(f);
}
double dJn(double x,int n,double d)
{
 int i;
 double fn,fn1,f;
 fn1 = Jn(x+d,n);
 fn = Jn(x,n);
 f = (fn1-fn)/d;
 return(f);
}
double Y0(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x3 = x2*x/3;
 x4 = x2*x2;
 x5 = x3*x3;
 x6 = x4*x2;
 x8 = x4*x4;
 x10 = x8*x2;
 x12 = x10*x2;
 if((x<3) && (x>0))
    f = 2/M_PI*log(x/2)*J0(x)+0.36746691+0.60559366*x2-0.74350384*x4+
        0.25300117*x6-0.04261214*x8+0.00427916*x10-0.00024846*x12;
 else
    if(x>3)
      f = 1/sqrt(x)*f0(x)*sin(Teta0(x));
    else
      f = -0;
return(f);
}
double Y1(double x)
{
 double f,x2,x3,x4,x5,x6,x8,x10,x12;
 x2 = x*x/9;
 x4 = x2*x2;
 x6 = x4*x2;
 x8 = x4*x4;
 x10 = x8*x2;
 x12 = x10*x2;
 if((x<3) && (x>0))
    f = 2/M_PI*log(x/2)*J1(x)-0.6366198/x+0.2212091*x2/x+2.1682709*x4/x-
        1.3164827*x6/x+0.3123951*x8/x-0.0400976*x10/x+0.0027873*x12/x;
 else
    if(x>3)
      f = 1/sqrt(x)*f1(x)*sin(Teta1(x));
    else
      f = -10;
return(f);
}
double Yn(double x,int n)
{
 int i,m;
 double fn,fn1,f;
 m = n;
 n = abs(n);
 switch(n)
        {
         case 0:
                f = Y0(x);
                break;
         case 1:
                f = Y1(x);
                break;
         default:
                 fn = Y1(x);
                 fn1 = Y0(x);
                for(i=2;i<=n;i++)
                   if(x!=0)
                     {
                      f = fn*2*(i-1)/x-fn1;
                      fn1 = fn;
                      fn = f;
                     }
                   else
                     f = -0;
                break;
         }
 if(m<0)
 if(n%2==1)
   f = f*(-1);
 return(f);
}
double dYn(double x,int n,double d)
{
 int i;
 double fn,fn1,f;
 fn1 = Yn(x+d,n);
 fn = Yn(x,n);
 f = (fn1-fn)/d;
 return(f);
}
complex<double> H1n(double x,int n)
{
 complex<double> f,I(0,1);
 f = Jn(x,n)+I*Yn(x,n);
return(f);
}
complex<double> dH1n(double x,int n,double d)
{
 int i;
 complex<double> fn,fn1,f;
 fn1 = H1n(x+d,n);
 fn = H1n(x,n);
 f = (fn1-fn)/d;
 return(f);
return(f);
}
complex<double> H2n(double x,int n)
{
 complex<double> f,I(0,1);
 f = Jn(x,n)-I*Yn(x,n);
return(f);
}
complex<double> dH2n(double x,int n,double d)
{
 int i;
/* complex<double> fn,fn1,f;
 fn1 = H2n(x+d,n);
 fn = H2n(x,n);
 f = (fn1-fn)/d;
 return(f);*/
 complex<double> f,I(0,1);
 f = dJn(x,n,d)-I*dYn(x,n,d);
return(f);
}
complex<double> powc(complex<double> a, int n)
{
int i;
complex<double> f(1,1);
if(n>0)
  {
   f = a;
   for(i=1;i<n;i++)
      {
       f *= a;
      }
  }
else
  {
   f = 1./a;
   for(i=1;i<abs(n);i++)
      {
       f /= a;
      }
  }
if(n==0)
  f=1.;
return (f);
}
double Jn(double x,int n)
{
int i,N=200;
double s=0.,t;
for(i=1;i<N;i++)
   {
    t = M_PI/N*i;
    s += cos(x*sin(t)-n*t)*M_PI/N;
   }
 s /= M_PI;
  if(n<0)
 if(abs(n)%2==1)
   s = s*(-1);
return(s);
}
double Yn_i(double x,int n)
{
 int i,m;
 double fn,fn1,f;
 m = n;
 n = abs(n);
 switch(n)
        {
         case 0:
                f = Y0(x);
                break;
         case 1:
                f = Y1(x);
                break;
         default:
                 fn = Y1(x);
                for(i=2;i<=n;i++)
                   if(x!=0)
                     {
                      f = (fn*Jn(x,i)-2./M_PI/x)/Jn(x,i-1);
                      fn = f;
                     }
                   else
                     f = -0;
                break;
         }
 if(m<0)
 if(n%2==1)
   f = f*(-1);
 return(f);
}
double Yn_1(double x,int n)
{
 int i,m;
 double f,d=0.01;
 m = n;
 n = abs(n);
 f = 1/sin(n*M_PI+d)*(Jn(x,n)*cos(n*M_PI+d)-Jn(x,-n));
 return(f);
}
double sign(double x)//Знаковая функция
{
 double r;
 if(x>0)
   r = 1;
 else
  {
   if(x<0)
     r = -1;
   else
     r = 0;
  }
return (r);
}
double pwn(double x,int n)//Wцелочисленная степень
{
 int i;
 double r;
 r = x;
 for(i=1;i<n;i++)
	{
	 r=r*x;
	}
return (r);
}
