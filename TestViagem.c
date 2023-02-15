#include "Viagem.h"
#include "TestViagem.h"
#include "stdio.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"


void testIniciaPassagemVendida() {
    // Cria uma passagem sem atributos
    struct passagem *passagem = criaPassagem();

    // Configura o código da passagem
    setCodigoDaPassagem(passagem, "12345678910");


    PassagemVendida *passagemVendida = iniciaPassagemVendida(passagem);

    if (strcmp(getCodigoDaPassagem(passagem), getCodigoDaPassagem(getPassagem(passagemVendida))) == 0) {
        if (getProximo(passagemVendida) == NULL) {
            printf(ANSI_COLOR_GREEN "testIniciaPassagemVendida(): Success!\n" ANSI_DEFAULT);
            liberaPassagemVendida(passagemVendida);
            return;
        }
    }

    printf(ANSI_COLOR_RED "testIniciaPassagemVendida(): Failed!\n" ANSI_DEFAULT);
    liberaPassagemVendida(passagemVendida);
}

void agrupaTestesViagem() {
    testIniciaPassagemVendida();
}