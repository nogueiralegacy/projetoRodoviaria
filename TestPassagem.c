#include "Passagem.h"
#include "TestPassagem.h"
#include "stdio.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testRecuperaPassagem() {
    Passagem *passagem = criaPassagem();

    recuperaPassagem(passagem, "testPassagem.csv", "testPassageiro.csv", "8070660");

    if (strcmp(getCodigoDaPassagem(passagem), "8070660") == 0) {
        if (getFileira(passagem) == 1) {
            if (getColuna(passagem) == 2) {
                if (getValor(passagem) == 100.00) {
                    if (strcmp(getCpf(getPassageiro(passagem)), "02037477148") == 0) {
                        if (strcmp(getNome(getPassageiro(passagem)), "Pedro Alberto") == 0) {
                        printf(ANSI_COLOR_GREEN "testRecuperaPassagem(): Success!\n" ANSI_DEFAULT);
                        liberaPassagem(passagem);
                        return;
                    }
                    }
                }
            }
        }
    }

    printf(ANSI_COLOR_RED "testRecuperaPassagem(): Failed!\n" ANSI_DEFAULT);
    liberaPassagem(passagem);
}


void testRecuperaTodasPassagens() {
    Passagem **passagens = recuperaTodasPassagens("testPassagem.csv", "testPassageiro.csv");

    if (strcmp(getCodigoDaPassagem(passagens[0]), "8070660") == 0) {
        if (strcmp(getCodigoDaPassagem(passagens[1]), "201202") == 0) {
             printf(ANSI_COLOR_GREEN "testRecuperaTodasPassagens(): Success!\n" ANSI_DEFAULT);
             liberaPassagem(passagens[0]);
             liberaPassagem(passagens[1]);
            free(passagens);
        }
    }

    printf(ANSI_COLOR_RED "testRecuperaTodasPassagens(): Failed!\n" ANSI_DEFAULT);
    liberaPassagem(passagens[0]);
    liberaPassagem(passagens[1]);
    free(passagens);
}
void agrupaTestesPassagem() {
    printf("------ Testes de Passagem.c ------\n");
    testRecuperaPassagem();
    printf("\n");
    testRecuperaTodasPassagens();
    printf("\n");
}