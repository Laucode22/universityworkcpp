#pragma once

#include "comun.h"
#include "errores.h"
#include "calendario.h"
#include "preguntas.h"

/*------Constantes------*/

const int MaxNombre = 20;
const int MaxFarmPedido = 5;
const int MaxPaciente = 20;
const int MaxFechas = 3000;
const int maxPedido = 100;

/*-----Definiciones de tipos -----*/
/*En este vector se guardara una cadena string con el nombre del paciente*/
typedef char Nombre[MaxNombre + 1];
/*Esta es la TAD del paciente, aqui se guarda su nombre, el numero de referencia y las coordenaadas de su ubicacion
en distancia y angulo*/
typedef struct TadPaciente {

  Nombre         Nombre_paciente;
  int            Ref;
  int            Distancia;
  int            Angulo;

};
/*Este vector guarda hasta 20 instancias de la TAD tadPaciente */
typedef TadPaciente Paciente[MaxPaciente];

/*Esta es la TAD del farmaco, aqui se guarda su nombre, su peso y las unidades de farmaco*/
typedef struct TadFarmaco {

  Nombre        Nombre_Farmaco;
  int           Peso;
  int           Unidades;

};
/*Este vector guarda hasta 5 instancias de la TAD tadFarmaco */
typedef TadFarmaco Farmaco[MaxFarmPedido];


/*Esta TAD guarda informacion sobre el calendario como dia, mes y año*/
typedef struct Calendario{
 int Dia;
 int Mes;
 int Anno;
 int ref_cal_paciente;
};

typedef Calendario CalendarioPedidos[MaxFechas];

/*Esta TAD guarda informacion sobre el pedido */
typedef struct TadPedido {

  Paciente             Pacientes;
  Farmaco              Farmacos;
  CalendarioPedidos    Calendarios;
  int                  punteroPedido;
  int                  punteroFarm;
  int                  punteroPaciente;
  int                  punteroCalen;
  int                  NumEnvios;
  int                  PesoPedido;

};

typedef TadPedido Pedidos[maxPedido];

typedef struct GestionPedidos{
  FuncionesComunes cmn;
  Errores err;
  Preguntas pr;
  CalendarioPedido calped;
 void Panel_Principal();
 /*Parte privada del TAD, no permitir acceso de nadie a ella*/
  private:
  Paciente Pacientes_ped;
  Pedidos Pedidos_ped;
  void AltaPaciente();
  void UbicarPaciente();
  void NuevoPedido();
  void ComprobarPaciente(int referencia);
  int ComprobarPeso(int peso, int unidades);
  void ListarPedidos();
  void CalendarioMensual();
};
