#pragma once

#include "comun.h"

/*Este TAD contendra funciones que señalan cuando hay un error e imprime que tipo de error*/
typedef struct Errores{
  FuncionesComunes Cmn_E;

  void EnterError();
  void Cadena_error();
  void Distancia_error();
  void Angulo_error();
  void Referencia_error();
  void Dia_error();
  void Mes_error();
  void Annio_error();
  void Peso_error();
  void DiasEntre_error();
};

