
/*
 *
 *
 *
 */

#include "bolzano.h"

bool criterio_de_parada(double a, double b, double error, int tipo) { // Para experimentar outros critérios.

  switch(tipo){
    case 1:
      return fabs(b - a) > error ? true : false; // Critério |b - a| < e

    case 2:
      return fabs(b - a) > error ? true : false; // Critério | x_(k + 1) - x_(k) | < e 

    default:
      return fabs(a) > error ? true :false;      // Critério | f(x) | < e
  }
}

double metodo_da_bissecCao(double (*func)(double x), double a, double b, double error) {  
  
  double x, fx, fa, fb;
  // double x_anterior;
  int i = 0; // Para printf.

  fa = func(a);  // Optei pelo fa e fb para evitar muitas chamadas de *func.  
  fb = func(b); // Talvez seja interessante observar alguma implementação que evite isso... 

  if(fa * fb >= 0){ // Tratamento de erro (P.S. idealmente nunca será usada)
    printf("> [ERRO]: O intervalo dado não satisfaz o teo. de Bolazano\n");
    exit(1);
  }

  do {
    x  = (a + b) / 2.0; // Recorta o intevalo no meio.
    fx = func(x);

    printf("        a = %+.15lf | fa = %+.15lf\n  [%2d]: b = %+.15lf | fb = %+.15lf\n        x = %+.15lf | fx = %+.15lf\n\n", 
        a, fa, i++, b, fb, x, fx);
    
    if(fa * fx < 0){  // Observa qual intervalo satisfaz o teo. Bolazano.
      // x_anterior = b;
      b  = x;
      fb = fx;
    }
    else{
      // x_anterior = a;
      a  = x;
      fa = fx;
    }

  } while(fabs(b - a) > error); // Critério de parada!

  return x;
}

double metodo_da_poscCao_falsa(double (*func)(double x), double a, double b, double error) {  
  
  double x, fx, fa, fb;
  // double x_anterior;

  fa = func(a); 
  fb = func(b);

  if(fa * fb >= 0){
    printf("> [ERRO]: O intervalo dado não satisfaz o teo. de Bolazano\n");
    exit(1);
  }

  if(fb - fa == 0){ // Tratamento da possibilidade de divisão por zero...
    printf("> [ERRO]: Divisão por zero\n");
    exit(1); 
  } // CONTUDO, é urgente uma verificação dentro do loop!

  do {
    x  = a - (fa * (b - a))/(fb - fa); // Encontra-se o ponto da reta def. (a, fa) -- (b, fb) que cruza a abscissa.

    /* Outra opção com multiplicação extra, a primeira me pareceu mais agradável...*/
    // x = (a * fb - b * fa ) / (fb - fa); 

    fx = func(x);
    
    if(fa * fx < 0){
      // x_anterior = b;
      b  = x;
      fb = fx;
    }
    else{
      // x_anterior = a;
      a  = x;
      fa = fx;
    }

  } while(fabs(b - a) > error); // Critério de parada!

  return x;
}
