#include "Passageiro.h"
#include "TestPassageiro.h"
#include <stdio.h>
#include <string.h>

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testIniciaPassageiroAtributos() {
    char *nome = "Joao";
    char *cpf = "12345678910";
    char *telefone = "10987654321";
    char *email = "joao@gmail.com";
    char *telefoneDeEmergencia = "01020304050";

    Passageiro *passageiro = iniciaPassageiro(nome, cpf, telefone, email, telefoneDeEmergencia);

    if (strcmp(getNome(passageiro), nome) == 0) {
        if (strcmp(getCpf(passageiro), cpf) == 0) {
            if (strcmp(getTelefone(passageiro), telefone) == 0) {
                if (strcmp(getEmail(passageiro), email) == 0) {
                    if (strcmp(getTelefoneDeEmergencia(passageiro), telefoneDeEmergencia) == 0) {
                        printf(ANSI_COLOR_GREEN "testIniciaPassageiroAtributos(): Success!\n" ANSI_DEFAULT);
                        liberaPassageiro(passageiro);
                        return;
                    }
                }
            }
        }
    } else {
        printf(ANSI_COLOR_RED "testIniciaPassageiroAtributos(): Failed!\n" ANSI_DEFAULT);
    }
}

void agrupaTestesPassageiro() {
    testIniciaPassageiroAtributos();
}