#include <stdio.h>
#include "errores.h"

/*Funcion que imprime error si la entrdad introducida no esta dentro de ninguna de las opciones*/
void Errores::EnterError(){
  Cmn_E.ClearConsole();
  printf("  ERROR: Entrada incorrecta.\n\n");
  Cmn_E.PauseConsole();
}
/*Esta fucncion imprime error cuando se ha introducido una cadena de chars fuera del rango 1 - 20 chars*/
void Errores::Cadena_error(){
  printf("  ERROR: Cadena introducida esta fuera del rango 1 - 20 caracteres");
}

/*Esta funcion imprime error si se ha introducido un numero menor que 0 o mayor que 10000*/
void Errores::Distancia_error(){
  printf("  ERROR: Distancia fuera de rango (hasta 10000 metros).\n\n");
}

/*Esta funcion inprime error si se ha intrducido un angulo fuera del rango */
void Errores::Angulo_error(){
  printf("  ERROR: Angulo fuera de rango (entre 0 - 2000 pi/radiantes).\n\n");
}
/*Esta funcion inprime error si se ha intrducido un nombre de paciente con mas de
*20 caracteres*/
void Errores::Referencia_error(){
 printf("   ERROR: La referencia introducida esta fuera de rango (entre 1 y 20).\n\n");
}

/*Esta funcion inprime error si se ha intrducido un numero que no esta entre 1 - 31 */
void Errores::Dia_error(){
 printf("   ERROR: El dia introducido no existe, por favor introducir entre 1 - 31.\n\n");
}
/*Esta funcion inprime error si se ha introducido un numero que no esta entre 1 - 12 */
void Errores::Mes_error(){
 printf("   ERROR: El mes introducido no existe, por favor introducir entre 1 - 12.\n\n");
}
/*Esta funcion inprime error si se ha intrducido un numero fuera del rango */
void Errores::Annio_error(){
 printf("   ERROR: El annio introducido esta fuera de rago( 1601 - 3000).\n\n");
}
/*Esta funcion inprime error si se ha intrducido un numero fuera del rango 0 - 3000 */
void Errores::Peso_error(){
 printf("   ERROR: El peso introducido esta fuera de rago( 0 - 3000 gramos).\n\n");
}

/*Esta funcion inprime error si se ha intrducido un numero fuera del rango 1 - 15 */
void Errores::DiasEntre_error(){
  printf("   ERROR: El numero introducido esta fuera de rango( 1 - 15 dias).\n\n");
}
