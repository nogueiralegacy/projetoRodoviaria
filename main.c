#ifdef __unix__
    #define SO_Linux
#elif defined(_WIN32) || defined(WIN32)
    #define SO_Windows
#endif

#include <stdio.h>
#include "Interface.h"

 /**
  * Metodo para encontrar em qual SO a aplicaçao ta rodando
  * @return TRUE (1) Se for Windows ou FALSE (0) se nao for
  */
 int defineSO() {
    int isWindows = 0;

    #ifdef SO_Windows
        isWindows = 1;
    #endif

    return isWindows;
}

int main() {
    int windows = defineSO();
    interfaceCompanhia(windows);
    return 0;
}