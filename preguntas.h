#pragma once

#include "comun.h"
#include "errores.h"


/*Este TAD esta compuesta por todas las fucniones que preguntan, interactuando
*con el usuario que luego lo introducido sera utilizado por otras funciones*/
typedef struct Preguntas{

  FuncionesComunes Cmn_P;
  Errores Err_P;

  void Identificador_pr(SString &s);
  void Distancia_pr(int &n);
  void Angulo_pr(int &n);
  bool Si_no_pr(SString s);
  void ReferenciaPaciente(int &n);
  void NumeroEnvios(int &n);
  void DiaEnvio(int &n);
  void MesEnvio(int &n);
  void AnnioEnvio(int &n);
  void Nombre_farmaco(SString &s);
  void Peso_Farmaco(int &n);
  void UniFarmacos(int &n);
  void DiasEntreEnvio(int &n);
  void FechasEnvio(SString s, int &n);
  void Dia(int &n);
  void Mes(int &n);
  void Annio(int &n);
  void SeleccionMes(int &n);
  void SeleccionAnnio(int &n);
};
