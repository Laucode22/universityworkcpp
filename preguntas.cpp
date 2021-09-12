#include <string.h>
#include <stdio.h>
#include <ctype.h>

#include "preguntas.h"

/*Funcion que pregunta el nombre del paciente y salta error si se introducen mas de 20 caracteres o menos de 1*/
void Preguntas::Identificador_pr(SString &s){

  int lengthString;
  printf("    Identificador(entre 1 y 20 caracteres)? ");
  Cmn_P.EnterString(s);
  lengthString = strlen(s);
  if(lengthString < 1 || lengthString > 20){
   Err_P.Cadena_error();
   Identificador_pr(s);
  }

}
/*Funcion que pregunta la distancia del paciente desde el almacen y salta error si se encuentra fuera del rango*/
void Preguntas::Distancia_pr(int &n){

 printf("    Distancia (hasta 10000 metros a plena carga)? ");
 Cmn_P.EnterNum(n);

 if(n < 0 || n > 10000){
  Err_P.Distancia_error();
  /*Vuelve a preguntar la distancia hasta que se introduzca un numero entre 0-10000*/
  Distancia_pr(n);
 }
}
/*Esta funcion pregunta el angulo dela ubicacion del paciendte desde el almacen,
 y salta error si esta fuera del rango*/
void Preguntas::Angulo_pr(int &n){

 printf("    Angulo (entre 0 y 2000 pi/1000 radiantes)? ");
 Cmn_P.EnterNum(n);

 if(n < 0 || n > 2000){
  Err_P.Angulo_error();
  /*Vuelve a preguntar hasta que se introduzca un numero dentro del rango*/
  Angulo_pr(n);
 }
}

/*Funciono booleana que recibe tru si la respuesta del usuario es S (si) y false si es n (no)
*hay que introducirle un vector de caracteres*/
bool Preguntas::Si_no_pr(SString s){

 char continuar;
 bool bContinuar;

 printf("%s (S/N)?", s);
 Cmn_P.EnterChar(continuar);

 continuar = toupper(continuar);
 if( continuar == 'S'){
   bContinuar = true;
 }else if( continuar == 'N'){
   bContinuar = false;
 }else{
   bContinuar = Si_no_pr(s);
 }
  return bContinuar;
}
/*Esta funcion pregunta la referencia del paciente, si se introduce un numero fuera del
*rango pregunta hasta que se introduzca uno entre 1 - 20*/
void Preguntas::ReferenciaPaciente(int &n){
   printf("    Ref. Paciente (entre 1 y 20): ");
   Cmn_P.EnterNum(n);

 if(n < 0 || n > 20){
  Err_P.Referencia_error();
  /*Vuelve a preguntar la referencia hasta que se introduzca un numero entre 0-20*/
  ReferenciaPaciente(n);
 }
}
/*pregunta el numero de envios que se queren de un mismo pedido*/
void Preguntas::NumeroEnvios(int &n){
  printf("    Numero de envios? ");
  Cmn_P.EnterNum(n);
}
/*Pregunta el dia del envio, si se introduce un numero fuera del rango 1 - 31 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::DiaEnvio(int &n){
  printf("    Dia del envio? ");
  Cmn_P.EnterNum(n);

 if(n < 1 || n > 31){
  Err_P.Dia_error();
  /*Vuelve a preguntar el dia hasta que se introduzca un numero entre 1 -31*/
  DiaEnvio(n);
 }
}
/*Pregunta el mes del envio, si se introduce un numero fuera del rango 1 - 12 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::MesEnvio(int &n){
  printf("    Mes del envio? ");
  Cmn_P.EnterNum(n);

 if(n < 1 || n > 12){
  Err_P.Mes_error();
  /*Vuelve a preguntar el mes hasta que se introduzca un numero entre 1 - 12*/
  MesEnvio(n);
 }
}
/*Pregunta el año del envio, si se introduce un numero fuera del rango 1601 - 3000 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::AnnioEnvio(int &n){
  printf("    Annio del envio? ");
  Cmn_P.EnterNum(n);

 if(n < 1601 || n > 3000){
  Err_P.Annio_error();
  /*Vuelve a preguntar el annio hasta que se introduzca un numero entre 1601 - 3000*/
  AnnioEnvio(n);
 }
}
/*Pregunta por el nombre del farmaco, que tiene que ser una cadena de hasta 20 caracteres,
* si se introduce menos de 1 o mas de 20 vuelve a preguntar*/
void Preguntas::Nombre_farmaco(SString &s){
  int lengthString;
  printf("    Nombre farmaco(entre 1 y 20 caracteres)? ");
  Cmn_P.EnterString(s);
  lengthString = strlen(s);
  if(lengthString < 1 || lengthString > 20){
   Err_P.Cadena_error();
   Nombre_farmaco(s);
  }
}
/*Pregunta el peso del farmaco, si se introduce un numero fuera del rango 1 - 3000 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::Peso_Farmaco(int &n){
  printf("    Peso farmaco(Menor de 3000 gramos)? ");
  Cmn_P.EnterNum(n);

 if(n < 0 || n > 3000){
  Err_P.Peso_error();
  /*Vuelve a preguntar el peso hasta que se introduzca un numero entre 0 - 3000*/
  Peso_Farmaco(n);
 }
}
/*Pregunta las unidades de farmaco que se quieren pedir*/
void Preguntas::UniFarmacos(int &n){
  printf("    Unidades de farmaco?");
  Cmn_P.EnterNum(n);
}
/*Pregunta el numero de dias entre envio y envio, si se introduce un numero fuera del rango
*1 - 15 pregunta otra vez hasta que se introduzca un numero valido*/
void Preguntas::DiasEntreEnvio(int &n){
  printf("    Numero de dias entre cada envio?(Entre 1 y 15 dias)? ");
  Cmn_P.EnterNum(n);

 if(n < 1 || n > 15){
  Err_P.DiasEntre_error();
  /*Vuelve a preguntar el numero de dias hasta que se introduzca un numero entre 1 - 15*/
  DiasEntreEnvio(n);
 }
}
/*Esta funcion recibe una cadena de caracteres, que en este caso sera Dia o Mes o Annio
*dependeiendo de la cadena comprueba el rango del numero que se introduzca, si se mete
*un numero fuera de rango volvera a preguntar hasta que se introduzca
*un numero valido*/
void Preguntas::FechasEnvio(SString s, int &n){
  printf("    %s del primer envio? ",s,n );
  Cmn_P.EnterNum(n);

 if(strcmp(s, "Dia") == 0){
   if(n < 1 || n > 31){
     Err_P.Dia_error();
     FechasEnvio(s,n);
   }
 }else if(strcmp(s, "Mes") == 0){
   if(n < 1 || n > 12){
     Err_P.Mes_error();
     FechasEnvio(s,n);
   }
 }else if(strcmp(s, "Annio") == 0){
   if(n < 1601 || n > 3000){
     Err_P.Annio_error();
     FechasEnvio(s,n);
   }
 }
 }
/*Pregunta el dia, si se introduce un numero fuera del rango 1 - 31 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::Dia(int &n){
  printf("Dia? ");
  Cmn_P.EnterNum(n);

 if(n < 1 || n > 31){
  Err_P.Dia_error();
  /*Vuelve a preguntar el dia hasta que se introduzca un numero entre 1 -31*/
  Dia(n);
 }
}
/*Pregunta el mes, si se introduce un numero fuera del rango 1 - 12 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::Mes(int &n){
  printf("Mes? ");
  Cmn_P.EnterNum(n);

 if(n < 1 || n > 12){
  Err_P.Mes_error();
  /*Vuelve a preguntar el mes hasta que se introduzca un numero entre 1 - 12*/
  Mes(n);
 }
}
/*Pregunta el año, si se introduce un numero fuera del rango 1601 - 3000 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::Annio(int &n){
  printf("Annio? ");
  Cmn_P.EnterNum(n);

 if(n < 1601 || n > 3000){
  Err_P.Annio_error();
  /*Vuelve a preguntar el año hasta que se introduzca un numero entre 1601 -3000*/
  Annio(n);
 }
}
/*Pregunta el mes a seleccionar, si se introduce un numero fuera del rango 1 - 12 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::SeleccionMes(int &n){
  printf("Seleccion mes? ");
  Cmn_P.EnterNum(n);

 if(n < 1 || n > 12){
  Err_P.Mes_error();
  /*Vuelve a preguntar el mes hasta que se introduzca un numero entre 1 - 12*/
  Mes(n);
 }
}
/*Pregunta el año a seleccionar, si se introduce un numero fuera del rango 1601 - 3000 pregunta
*otra vez hasta que se introduzca un numero valido*/
void Preguntas::SeleccionAnnio(int &n){
  printf("Seleccion annio? ");
  Cmn_P.EnterNum(n);

 if(n < 1601 || n > 3000){
  Err_P.Annio_error();
  /*Vuelve a preguntar el año hasta que se introduzca un numero entre 1601 -3000*/
  Annio(n);
 }
}
