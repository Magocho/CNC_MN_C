#include "bolzano.h"

double fx3(double x){ return pow(2, x) - 3*x;}
double fx4(double x){ return x*x - 5*sin(x);}
double fx5A(double x){ return pow(M_E, x) - x*x + 3*x - 2;}
double fx5B(double x){ return x * cos(x) - 2*x*x + 3*x - 1;}
double fx6(double x){ return x - cbrt(25);}
double fx7(double x){ return (x*x*x) + x - 4.0;}
double fx8(double x){ return cos(x) - sqrt(x);}
double fx9(double x){ return pow(M_E, -x) - x;}
double fx10(double x){ return 200 * (2*log(40) - log(1600 - 27 * x)) + 9.8 * x - 100;}

int main()
{
  printf("Resultado = %lf\n", metodo_da_bissecCao(&fx10, 6, 8, 0.008));
  printf("Resultado = %lf\n", metodo_da_bissecCao(&fx9, 0, 1, 0.001));
  return 0;
}
