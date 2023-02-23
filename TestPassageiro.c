#include "Passageiro.h"
#include "TestPassageiro.h"
#include <stdio.h>

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
    }

        printf(ANSI_COLOR_RED "testIniciaPassageiroAtributos(): Failed!\n" ANSI_DEFAULT);
        liberaPassageiro(passageiro);
}


void testPersistenciaPassageiro() {
    Passageiro *passageiro = criaPassageiro();

    setNome(passageiro, "Daniel Nogueira");
    setCpf(passageiro, "12345678910");
    setEmail(passageiro, "daniel@gmail.com");
    setTelefone(passageiro, "10987654321");
    setTelefoneDeEmergencia(passageiro, "01020304050");

    salvaPassageiro(passageiro, "passageiro.csv");
    liberaPassageiro(passageiro);

    Passageiro *passageiroRecuperado = criaPassageiro();

    recuperaPassageiro(passageiroRecuperado, "passageiro.csv");

    if (strcmp(getNome(passageiroRecuperado), "Daniel Nogueira") == 0) {
        if (strcmp(getEmail(passageiroRecuperado), "daniel@gmail.com") == 0){
            printf(ANSI_COLOR_GREEN "testPersistencia(): Sucess!\n" ANSI_DEFAULT);
            liberaPassageiro(passageiroRecuperado);
            return;
        }
    }

    printf(ANSI_COLOR_RED "testPersistencia(): Failed!\n" ANSI_DEFAULT);
    liberaPassageiro(passageiroRecuperado);
}

void agrupaTestesPassageiro() {
    printf("------ Testes de Passageiro.c ------\n");
    testIniciaPassageiroAtributos();
    printf("\n");
    testPersistenciaPassageiro();
    printf("\n");
}