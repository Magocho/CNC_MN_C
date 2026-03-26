#include "bolzano.h"

bool teo_bolzano(double a, double b){
  return (a * b < 0) ? true : false;
}

bool criterio_de_parada(double dif, double fx, double x, double x_anterior, double error){
  if(fabs(dif) <= error && fabs(fx) <= error && fabs(x - x_anterior) <= error)
    return true;
  else return false;
}

double metodo_da_bissecCao(double (*func)(double x), double a, double b, double error)
{ 
  double atual, anterior, lim_sup, lim_inf;
  atual = b;
  anterior = 0;
  lim_sup = b;
  lim_inf = a;

  atual = (lim_inf + lim_sup)/2.0;

  while(!(criterio_de_parada((lim_sup - lim_inf), func(atual), atual, anterior, error))){

    anterior = atual;

    if(teo_bolzano(func(lim_inf), func(atual)))
      lim_sup = atual;
    else lim_inf = atual;

    atual = (lim_inf + lim_sup)/2.0;
  }
  return atual;
}

double metodo_da_bissecCao_Melhorado(double (*func)(double x), double a, double b, double error)
{ 
  double x, anterior, fx, fa, fb;

  fa = func(a);
  fb = func(b);

  if(fa * fb >= 0)
    return 0;

  x = (a + b) / 2.0;
  anterior = x;

  while(fabs(b - a) > error){

    x = (a + b) / 2.0;
    fx = func(x);

    if(fa * fx < 0){
      b = x;
      fb = fx;
    }
    else{
      a = x;
      fa = fx;
    }
    
    if(fabs(x - anterior) <= error && fabs(fx) <= error)
      break;

    anterior = x;
  }
  return x;
}
