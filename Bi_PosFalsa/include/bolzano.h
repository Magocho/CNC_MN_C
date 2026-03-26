#ifndef BOLZANO_H_INCLUDED
#define BOLZANO_H_INCLUDED

#include<stdio.h>
#include<stdbool.h>
#include <math.h>

double metodo_da_bissecCao(double (*func)(double x), double a, double b, double error);

double metodo_da_bissecCao_Melhorado(double (*func)(double x), double a, double b, double error);
#endif
