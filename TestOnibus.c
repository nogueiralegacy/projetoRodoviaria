#include <stdio.h>
#include "onibus.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testIniciaOnibusCodigo() {
    Onibus *onibus = iniciaOnibus("12345678910");
    char *codigo = getCodigoDoOnibus(onibus);
    if (strcmp(codigo, "12345678910") == 0) {
        printf(ANSI_COLOR_GREEN "testIniciaOnibusCodigo(): Success!\n" ANSI_DEFAULT);
    } else {
        printf(ANSI_COLOR_RED "testIniciaOnibusCodigo(): Failed!\n" ANSI_DEFAULT);
    }

    liberaOnibus(onibus);
}

void testIniciaOnibusAssentos() {
    Onibus  *onibus = iniciaOnibus("12345678910");

    for (int fileira = 0; fileira < getQuantidadeDeFileiras(onibus); fileira++) {
        for (int coluna = 0; coluna < getQuantidadeDeColunas(onibus); coluna++) {
            char **assento = getAssentos(onibus);
            if (assento[fileira][coluna] != 'L') {
                printf(ANSI_COLOR_RED "testIniciaOnibusAssentos(): Failed!\n" ANSI_DEFAULT);
            }
        }
    }

    printf(ANSI_COLOR_GREEN "testIniciaOnibusAssentos(): Success!\n" ANSI_DEFAULT);
    liberaOnibus(onibus);
}

void agrupaTestesOnibus() {
    testIniciaOnibusCodigo();
    testIniciaOnibusAssentos();
}