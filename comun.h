#pragma once

/*Este vector contendra hasta 20 caracteres*/
typedef char SString[21];

/*Vector temporal para la busqueda de los trayectos, cada busqueda se resetea*/
typedef int VTrayecto[31];
/*Este TAD contendra funciones comunes
**que seran utilizados en distintas funciones del programa*/

typedef struct FuncionesComunes {

 void EnterChar(char &c);
 void EnterNum(int &n);
 void EnterString(SString &s);
 void ClearConsole();
 void PauseConsole();

};


