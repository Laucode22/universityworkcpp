#pragma once

#include "comun.h"
/*Este vector me servira para almacenar hasta 31 dias que usare para busqueda temporal*/
typedef int VectorDias[31];

/*Este TAD almacena todas las fucniones que se utilizan para
imprimir un mes*/
typedef struct CalendarioPedido{

  bool esBisiesto(int & anno);
  int diasMes(int & mes, int & anno);
  void nombreMes(int & mes);
  void imprimirAnno(int & mes, int & anno);
  int zeller(int ano,int mes, int dia);
  void ImprimirMes(VectorDias vec_tmp,int mes, int anno);
};
