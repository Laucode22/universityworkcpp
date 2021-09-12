#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "comun.h"

/*Esta funcion recibe un char del usuario y lo pasa a consola */
 void FuncionesComunes::EnterChar(char &c){

  fflush(stdin);
  scanf("%c", &c);

 }
 /*Esta funcion recibe un numero del usuario y lo pasa a consola */
 void FuncionesComunes::EnterNum(int &n){

  fflush(stdin);
  scanf("%d", &n);

 }
/*Esta funcion recibe una cadena de caracteres del usuario y lo pasa a consola */
void FuncionesComunes::EnterString(SString &s){

  fflush(stdin);
  scanf("%[^\n]s", &s);

}

 /*Esta funcion limpia la consola*/
 void FuncionesComunes::ClearConsole(){

   system("cls");

 }
 /*Esta funcion para el programa hasta que el usuario pulse una tecla*/
 void FuncionesComunes::PauseConsole(){

 printf("\n\n");
 system("pause");

 }
