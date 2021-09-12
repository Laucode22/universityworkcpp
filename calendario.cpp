#include<stdio.h>
#include "calendario.h"

/*Esta funcion devuelve true si el año introducido es bisiesto
* y devuelve false si no lo es*/
bool CalendarioPedido::esBisiesto(int & anno){
  if(anno % 4 == 0 && (anno % 100 != 0 || anno% 400 == 0)){
   return true;
  }else{
   return false;
  }
}

/*Esta funcion recibe dos parametros , mes y año,
*y devuelve el numero de dias que tiene dicho mes*/
int CalendarioPedido::diasMes(int & mes, int & anno){
  int dias;
  if((mes==2)&& esBisiesto(anno)){
    dias = 29;
   return dias;
  }else if(mes ==2){
   dias = 28;
   return dias;
  }else if ( (mes ==4) || (mes ==6) || (mes ==9) || (mes ==11)){
   dias = 30;
   return dias;
  }else{
  dias = 31;
  return dias;
  }
}
/*Esta fucnion imprime los meses del año*/
void CalendarioPedido::nombreMes(int & mes){
if(mes == 1){
printf("ENERO");
}else if(mes == 2){
printf("FEBRERO");
}else if(mes == 3){
printf("MARZO");
}else if(mes == 4){
printf("ABRIL");
}else if(mes == 5){
printf("MAYO");
}else if(mes == 6){
printf("JUNIO");
}else if(mes == 7){
printf("JULIO");
}else if(mes == 8){
printf("AGOSTO");
}else if(mes == 9){
printf("SEPTIEMBRE");
}else if(mes == 10){
printf("OCTUBRE");
}else if(mes == 11){
printf("NOVIEMBRE");
}else if(mes == 12){
printf("DICIEMBRE");
}
}
/*Esta funcion imrpime el año con espacios para imrpimir en
*la misma linea el mes*/
void CalendarioPedido::imprimirAnno(int & mes, int & anno){
 switch(mes){
   case 2:
   case 10:
   printf("%20d" ,anno);
   break;
   case 5:
     printf("%23d" ,anno);
   break;
   case 8:
   printf("%21d" ,anno);
   break;
   case 9:
   printf("%17d" ,anno);
   break;
   case 11:
   case 12:
   printf("%18d" ,anno);
   break;
   default:
   printf("%22d" ,anno);
 }
}

/*Esta funcion me devuelve el dia de la semana en la que
*empieza el mes del año introducido*/
int CalendarioPedido::zeller(int ano,int mes, int dia){

    int a = (14-mes)/12;
    int y = ano - a;
    int m = mes + 12*a - 2;

    int d = (dia + y+ y/4 - y/100 + y/400 + (31*m)/12)%7;
      if ( d == 0 ) {
      d = 6;
    } else {
      d--;
    }
    return d;
  }
/*Esta funcion imprime el mes, pero no todos los dias, los dias
*que se imprimiran dependen del vector vec_tmp que se introduzca como parametro*/
void CalendarioPedido::ImprimirMes(VectorDias vec_tmp,int mes, int anno){
  bool bisiesto = false;
  int dias_mes;
  int comienzoMes;
  int Puntero = 0;
  int puntero_calen = 0;

  bisiesto = esBisiesto(anno);
  dias_mes = diasMes(mes, anno);
  comienzoMes = zeller(anno, mes,1);
  printf("\n\nPedidos del mes o vuelos del Dron\n\n");
  printf("    ");
  nombreMes(mes);
  imprimirAnno(mes, anno);
  printf("\n   _____________________________\n");
    printf("    L   M   X   J   V  | S   D    \n");

    /* 1º for: desde 1 hasta el total de días que tenga el mes en cuestión. */
    for (int i = 1; i <= dias_mes; i++) {

        if (i == 1) {

            printf("    ");
        }

        /* 2º for: imprime los puntos (.) necesarios antes de que empiece el primer día del mes. */
        for (int k = 0; k < comienzoMes; k++) {

            printf("  ");

            /* Si es viernes, imprime la barra de separación de fin de semana. */
            if (k == 4) {

                printf(" | ");
            }
            else {

                printf("  ");
            }

            Puntero++;
        }/* Fin 2º for */

        /* Se anula la variable "comienzoMes" para que no entre mas en el 1º for */
        comienzoMes = -1;
        if (vec_tmp[puntero_calen] == i) {

            if (i < 10) {

                printf("0%d", i);
            }
            else {

                printf("%2d", i);
            }


            puntero_calen++;
        }
        else {

            printf("--");
        }

        /* Si la posición del puntero no es viernes, imprime doble espacio. */
        if ((Puntero % 7) != 4) {

            printf("  ");
        }

        /* Si la posición del puntero es viernes, imprime la barra de separación. */
        if ((Puntero % 7) == 4) {

            printf(" | ");
        }

        /* Si la posición del puntero es domingo, imprime salto de línea. */
        if ((Puntero % 7) == 6) {

            printf("\n    ");
        }

        /* Si el 1º for ha imprimido todos los días del mes, comienza a imprimir los puntos hasta terminar el mes. */
        if (i == dias_mes) {

          /* 3º for: imrpime puntos desde la posición actual del puntero hasta el domingo mas cercano */
          for (int k = 0; k < (6 - (Puntero % 7)); k++) {

              printf("--");

              /* Imprime una barra si es viernes. */
              if ((Puntero % 7) + k + 1 == 4) {

                  printf(" | ");
              }
              else {

                  printf("  ");
              }
          }/* Fin 3º for */
        }

        /* Actualiza la posición del puntero a cada vuelta del for principal. */
        Puntero++;
    }

}
