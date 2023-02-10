#include <stdio.h>
#include "onibus.h"

int main() {
    Onibus *onibus = iniciaOnibus("12345678910");

    printf("Codigo do onibus: %s\n", getCodigoDoOnibus(onibus));
    printf("Quantidade total de assentos: %d\n", getQuantidadeDeAssentos(onibus));

    return 0;
}