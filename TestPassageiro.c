#include "Passageiro.h"
#include "TestPassageiro.h"
#include <stdio.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testRecuperarPassageiro() {
    Passageiro *passageiro = criaPassageiro();
    //Arquivo de passageiros para teste já com alguns
    // passageiros cadastrados para facilitar o desenvolvimento
    // Testa o metodo recuperar Passagens
    recuperaPassageiro(passageiro, "testPassageiro.csv", "02037477148");

    if (strcmp(getNome(passageiro), "Pedro Alberto") == 0) {
        if (strcmp(getCpf(passageiro), "02037477148") == 0) {
            if (strcmp(getTelefone(passageiro), "5656565") == 0) {
                if (strcmp(getEmail(passageiro), "pedro@gmail.com") == 0) {
                    if (strcmp(getTelefoneDeEmergencia(passageiro), "6565656") == 0) {
                        printf(ANSI_COLOR_GREEN "testRecuperaPassageiro(): Success!\n" ANSI_DEFAULT);
                        liberaPassageiro(passageiro);
                        return;
                    }
                }
            }
        }
    }

        printf(ANSI_COLOR_RED "testRecuperaPassageiro(): Failed!\n" ANSI_DEFAULT);
        liberaPassageiro(passageiro);
}

void agrupaTestesPassageiro() {
    printf("------ Testes de Passageiro.c ------\n");
    testRecuperarPassageiro();
    printf("\n");
}