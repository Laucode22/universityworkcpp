#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "generalTad.h"

/*Esta funcion imprimira el panel principal dando 6 opciones diferentes.
**Dependiendo del valor introducido por el usuario se realizara una opcion u otra
**En caso de introducir un caracter que no esta dentro de las opciones, salta error y se vuelve a imprimir
**el panel principal hast que se introduzca un caracter de los indicados.
*/
void GestionPedidos::Panel_Principal(){
  char charUser;

  cmn.ClearConsole();
  printf("FarmaDron:Distribucion de Farmacos con Dron\n");
  printf("    Alta nuevo paciente                       (Pulsar A)\n");
  printf("    Ubicar pacientes                          (Pulsar U)\n");
  printf("    Nuevo pedido                              (Pulsar N)\n");
  printf("    Lista diaria de pedidos                   (Pulsar L)\n");
  printf("    Calendario mensual de pedidos             (Pulsar C)\n");
  printf("    Salir                                     (Pulsar S)\n");
  printf("Teclear una opcion valida (A|U|N|L|C|S)?\n");

  cmn.EnterChar(charUser);
  charUser = toupper(charUser);
  switch (charUser){
   case 'A':
    AltaPaciente();
   break;
   case 'U':
    UbicarPaciente();
   break;
   case 'N':
    NuevoPedido();
   break;
   case 'L':
    ListarPedidos();
   break;
   case 'C':
    CalendarioMensual();
   break;
   case 'S':
   break;
   default:
   err.EnterError();
   Panel_Principal();
  }
}
/*Esta funcion se encarga de dar de alta a un nuevo paciente. Pueden existir
**hasta 20 pacientes diferentes. No se deben exceder los limites de distancia y angulo, donde
**se encuentranlos pacientes ubicados. Una vez introducido los datos se pregunta si estan todos
**correctos, y solo si la respuesta es positiva se guardan los datos en el sistema del dron.
*/
void GestionPedidos::AltaPaciente(){
 Nombre identificador_alta = "";
 int distancia_alta;
 int angulo_alta;
 bool continuar_alta = false;
 bool otra_alta = false;
 int referencia_alta;
 //int numPedido;

  cmn.ClearConsole();
  printf("Alta nuevo paciente:\n\n");

do{
  pr.Identificador_pr(identificador_alta);
  pr.Distancia_pr(distancia_alta);
  pr.Angulo_pr(angulo_alta);

continuar_alta = pr.Si_no_pr("Datos correctos");

if(continuar_alta){
  if(Pedidos_ped[0].punteroPaciente < 0){
  referencia_alta = 0;
  }else{
    referencia_alta = Pedidos_ped[0].punteroPaciente + 1;
  }
  Pacientes_ped[referencia_alta].Ref = referencia_alta;
  strcpy(Pacientes_ped[referencia_alta].Nombre_paciente, identificador_alta);
  Pacientes_ped[referencia_alta].Distancia = distancia_alta;
  Pacientes_ped[referencia_alta].Angulo = angulo_alta;
  Pedidos_ped[0].punteroPaciente = referencia_alta;
}
otra_alta = pr.Si_no_pr("Otro paciente");
}while(otra_alta);
Panel_Principal();
}

/*La siguiente funcion imprime la informacion de todos los
**pacientes existente en el sistema conteniendo la referencia,
**identificador(nombre), distancia y angulo*/
void GestionPedidos::UbicarPaciente(){

  cmn.ClearConsole();
  printf("Lista de pacientes y su ubicacion:\n\n");
  printf("    Ref.       Identificador           Distancia          Angulo\n\n");
  for(int i = 1; i <= Pedidos_ped[0].punteroPaciente; i++){
  printf("%7d%20s%20d%16d\n",Pacientes_ped[i].Ref,Pacientes_ped[i].Nombre_paciente,
   Pacientes_ped[i].Distancia,Pacientes_ped[i].Angulo);
  }
  cmn.PauseConsole();
  Panel_Principal();
}
/*La siguiente funcion se encarga de introduci un nuevo pedido al sistema.
**Se debe comprobar que el paciente que va a hacer el pedido,las fechas
**en las que se va a hacer el pedido existen.Por otra parte
** comprobar que el peso ,dependiendo de las unidades, no excede
**el peso que puede levantar el dron.
**Por ultimo da la oportunidad de añadir numerosos farmacos por pedido (hasta 5 )y
**numerosos pedidos ( hasta 100 )
*/
 void GestionPedidos::NuevoPedido(){
  int ref_np;
  int numEnvio;
  int diaEnvio;
  int mesEnvio;
  int annioEnvio;
  int diasEntre;
  Nombre nombreFarm = "";
  int pesoFarm;
  int unidadesFarm;
  int pesoPedido;
  int counterFarmaco = 0;
  int counterCalendario;
  int numeroPedido;
  bool newFarmaco = false;
  bool newPedido = false;

  cmn.ClearConsole();
 printf("Nuevo pedido:\n\n");
 do{
 pr.ReferenciaPaciente(ref_np);
 ComprobarPaciente(ref_np);
 pr.NumeroEnvios(numEnvio);
 if(numEnvio == 1){
 pr.DiaEnvio(diaEnvio);
 pr.MesEnvio(mesEnvio);
 pr.AnnioEnvio(annioEnvio);
 }else{
 pr.DiasEntreEnvio(diasEntre);
 pr.FechasEnvio("Dia", diaEnvio);
 pr.FechasEnvio("Mes", mesEnvio);
 pr.FechasEnvio("Annio", annioEnvio);
 }
 if(calped.diasMes(mesEnvio, annioEnvio) < diaEnvio){
  printf("El dia seleccionado no existe en el mes del annio elegido");
  cmn.PauseConsole();
  Panel_Principal();
 }
 if(Pedidos_ped[0].punteroCalen < 0){
   counterCalendario = 0;
  Pedidos_ped[0].punteroCalen = 0;
 }else{
   counterCalendario = Pedidos_ped[0].punteroCalen + 1;
 }

  do{
   pr.Nombre_farmaco(nombreFarm);
   pr.Peso_Farmaco(pesoFarm);
   pr.UniFarmacos(unidadesFarm);
   pesoPedido = ComprobarPeso(pesoFarm, unidadesFarm);
   if(Pedidos_ped[0].punteroPedido < 0){
    numeroPedido = 0;
   }
   numeroPedido = Pedidos_ped[0].punteroPedido + 1;
   //Sumarle al peso ya existente el peso recibido y guardarlo en pesoPedido
   pesoPedido = pesoPedido + Pedidos_ped[numeroPedido].PesoPedido;
   if(pesoPedido == 0){
    printf("Se ha excedido el peso que puede levantar el dron (hasta 3000 gramos por viaje)");
    cmn.PauseConsole();
    Panel_Principal();
   }
   //Guardar todos los datos del farmaco
   strcpy(Pedidos_ped[numeroPedido].Farmacos[counterFarmaco].Nombre_Farmaco, nombreFarm);
   Pedidos_ped[numeroPedido].Farmacos[counterFarmaco].Peso = pesoFarm;
   Pedidos_ped[numeroPedido].Farmacos[counterFarmaco].Unidades = unidadesFarm;
   Pedidos_ped[numeroPedido].PesoPedido = pesoPedido;


   newFarmaco = pr.Si_no_pr("Otro farmaco");
   if(counterFarmaco+1 > 4){
   newFarmaco = false;
   printf("No se pueden añadir mas de 5 farmacos por pedido");
   cmn.PauseConsole();
   }else{
     counterFarmaco++;
   }
  }while(newFarmaco);
   Pedidos_ped[numeroPedido].punteroFarm = counterFarmaco;
   counterFarmaco = 0;
   newPedido = pr.Si_no_pr("Otro pedido");
//Guardar todos losdatos del pedido

   Pedidos_ped[numeroPedido].Calendarios[counterCalendario].Dia = diaEnvio;
   Pedidos_ped[numeroPedido].Calendarios[counterCalendario].Mes = mesEnvio;
   Pedidos_ped[numeroPedido].Calendarios[counterCalendario].Anno = annioEnvio;
   Pedidos_ped[numeroPedido].Calendarios[counterCalendario].ref_cal_paciente = ref_np-1;
   Pedidos_ped[numeroPedido].Pacientes[ref_np-1].Ref = Pacientes_ped[ref_np-1].Ref;
   Pedidos_ped[numeroPedido].Pacientes[ref_np-1].Distancia = Pacientes_ped[ref_np-1].Distancia;
   Pedidos_ped[numeroPedido].Pacientes[ref_np-1].Angulo = Pacientes_ped[ref_np-1].Angulo;
   strcpy(Pedidos_ped[numeroPedido].Pacientes[ref_np-1].Nombre_paciente, Pacientes_ped[ref_np-1].Nombre_paciente);
   Pedidos_ped[0].punteroCalen = counterCalendario;
   Pedidos_ped[0].punteroPedido = numeroPedido;
   counterCalendario++;
   numeroPedido++;

}while(newPedido);

 Panel_Principal();
}

/*Funcion que comprueba si el paciente existe en el sistema
**Si no es asi se vuelve al panel principal*/

void GestionPedidos::ComprobarPaciente(int referencia){
 if(Pacientes_ped[referencia].Ref < referencia){
  printf("El paciente introducido no ha sido dado de alta todavia");
  cmn.PauseConsole();
  Panel_Principal();
 }
}
/*
**Esta funcion recibe el peso y las unidades de un farmaco y devuelve
*el peso total
*/
int GestionPedidos::ComprobarPeso(int peso, int unidades){
  int pesoPedido;
  pesoPedido = peso*unidades;
  if(pesoPedido < 3000){
   return pesoPedido;
  }else{
   return 0;
  }
}
/*
*Esta funcion pregunta el dia, mes y año e imprime los pedidos registrados en
*el sistema para dicha fecha.
*/

void GestionPedidos::ListarPedidos(){

  int diaLista;
  int mesLista;
  int annioLista;
  int puntero_paciente;

 cmn.ClearConsole();
 printf("Lista diaria de pedidos: \n\n");
 pr.Dia(diaLista);
 pr.Mes(mesLista);
 pr.Annio(annioLista);
 for(int i=0; i<maxPedido; i++){
  for(int j= 0; j<MaxFechas; j++){
     if(Pedidos_ped[i].Calendarios[j].Dia == diaLista &&
     Pedidos_ped[i].Calendarios[j].Mes == mesLista &&
     Pedidos_ped[i].Calendarios[j].Anno == annioLista){
      printf("    Pedido %2d\n", i);
      puntero_paciente = Pedidos_ped[i].Calendarios[j].ref_cal_paciente;
      printf(" Ubicacion destino: Distancia:%5d y Angulo:%5d\n",
       Pacientes_ped[puntero_paciente+1].Distancia,
       Pacientes_ped[puntero_paciente+1].Angulo);

      for(int z = 0; z< Pedidos_ped[i].punteroFarm; z++){
      printf("%3d Unidades %20s      Peso:%5d gramos\n", Pedidos_ped[i].Farmacos[z].Unidades,
      Pedidos_ped[i].Farmacos[z].Nombre_Farmaco, Pedidos_ped[i].Farmacos[z].Peso);
      }
      printf("\n                    Peso Total del envio:%6d\n\n",Pedidos_ped[i].PesoPedido );
     }
  }
 }

cmn.PauseConsole();
 Panel_Principal();
}
/*
*Esta funcion pregunta el mes y el año e imrpime un calendario donde se pueden ver
*todos los dias, de dicho año y mes, en los que hay programados pedidos
*/

void GestionPedidos::CalendarioMensual(){
int mes_sel;
int annio_sel;
int counter_dias;
VectorDias  vec_dias;
bool continuar = false;

 cmn.ClearConsole();
 printf("Calendario mensual de pedidos:\n");
 do{
   counter_dias = 0;
 pr.SeleccionMes(mes_sel);
 pr.SeleccionAnnio(annio_sel);
for(int k = 0; k < Pedidos_ped[0].punteroPaciente;k++){
for(int l = 1; l <= 31; l++){
 for(int i = 0; i <= Pedidos_ped[0].punteroPedido; i++){
  for(int j = 0; j <= Pedidos_ped[0].punteroCalen; j++){
   if(Pedidos_ped[i].Calendarios[j].Dia == l &&
   Pedidos_ped[i].Calendarios[j].Mes == mes_sel &&
   Pedidos_ped[i].Calendarios[j].Anno == annio_sel){
    vec_dias[counter_dias] = l;
    counter_dias++;
   }
  }
 }
}
}
 calped.ImprimirMes(vec_dias, mes_sel, annio_sel);
 printf("\n\n");
 continuar = pr.Si_no_pr("Mostrar otro mes");
 }while(continuar);
 Panel_Principal();
}

