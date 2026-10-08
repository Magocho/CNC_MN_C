
/*
 *
 *
 *
 */

#include "bolzano.h"

double metodo_de_iteracCao_linear(double (*f)(double x), double (*g)(double x), double x_o, double error) {
  // Ou do ponto fixo...
  // Obs. Assume-se duas coisas nessa função:
  /*
   * i. para g(x) e g'(x) são contínuas no intervalo [a, b], no qual x_o está contido.
   * ii. para | g'(x) | < 1 , para todo xi pertencente a [a,b] 
   */
  
  double fx, xi, x = x_o;
  int i = 0; // Para printf.

  printf("        i = %d | x = %+.15lf | fx = %+.15lf | gx = %+.15lf\n", i, x, fx, gx);

  do {

    xi = x;       // Reserva o anterior
    x  = g(x);   // Calcula o próximo x
    fx = f(x);  // Determina seu valor em f
    
    printf("        i = %d | x = %+.15lf | fx = %+.15lf | gx = %+.15lf\n", i++, x, fx, gx);

    if(fabs(fx) < error) // Primeiro critério de parada.
      return x;

  } while(fabs(x - xi) > error); // Segundo critério de parada!

  return x;
}
