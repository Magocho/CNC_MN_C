#include "bolzano.h"

double fx(double x){
  return (x*x*x) - x - 2.0;
}

double fx3(double x){
  return pow(2, x) - 3*x;
}

double fx4(double x){
  return x*x - 5*sin(x);
}

double fx5A(double x){
  return pow(M_E, x) - x*x + 3*x - 2;
}

double fx5B(double x){
  return x * cos(x) - 2*x*x + 3*x;
}

void main()
{
  printf("Resultado = %lf\n", metodo_da_bissecCao(&fx, 1, 2, 0.0000000005));
  printf("Resultado = %lf\n", metodo_da_bissecCao_Melhorado(&fx3, 0, 1, 0.01));
  printf("Resultado = %lf\n", metodo_da_bissecCao_Melhorado(&fx3, 3, 4, 0.1));
}
