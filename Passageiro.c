#include <string.h>
#include <stdlib.h>
#include "Passageiro.h"

struct passageiro {
    char nome[50];
    char cpf[12];
    char telefone[12];
    char email[50];
    char telefoneDeEmergencia[12];
};

typedef struct passageiro Passageiro;

Passageiro *iniciaPassageiro(char nome[50], char cpf[12], char telefone[12], char email[50], char telefoneDeEmergencia[12]) {
    Passageiro *passageiro = (Passageiro *) malloc(sizeof(Passageiro));
    strcpy(passageiro->nome, nome);
    strcpy(passageiro->cpf, cpf);
    strcpy(passageiro->telefone, telefone);
    strcpy(passageiro->email, email);
    strcpy(passageiro->telefoneDeEmergencia, telefoneDeEmergencia);

    return passageiro;
}

Passageiro *criaPassageiro() {
    Passageiro *passageiro = (Passageiro *) malloc(sizeof(Passageiro));
    strcpy(passageiro->nome, "");
    strcpy(passageiro->cpf, "");
    strcpy(passageiro->telefone, "");
    strcpy(passageiro->email, "");
    strcpy(passageiro->telefoneDeEmergencia, "");

    return passageiro;
}

void liberaPassageiro(Passageiro *passageiro) {
    free(passageiro);
}

char *getNome(Passageiro *passageiro) {
    return passageiro->nome;
}

char *getCpf(Passageiro *passageiro) {
    return passageiro->cpf;
}

char *getTelefone(Passageiro *passageiro) {
    return passageiro->telefone;
}

char *getEmail(Passageiro *passageiro) {
    return passageiro->email;
}

char *getTelefoneDeEmergencia(Passageiro *passageiro) {
    return passageiro->telefoneDeEmergencia;
}

void setNome(Passageiro *passageiro, char nome[50]) {
    strcpy(passageiro->nome, nome);
}

void setCpf(Passageiro *passageiro, char cpf[12]) {
    strcpy(passageiro->cpf, cpf);
}

void setTelefone(Passageiro *passageiro, char telefone[12]) {
    strcpy(passageiro->telefone, telefone);
}

void setEmail(Passageiro *passageiro, char email[50]) {
    strcpy(passageiro->email, email);
}

void setTelefoneDeEmergencia(Passageiro *passageiro, char telefoneDeEmergencia[12]) {
    strcpy(passageiro->telefoneDeEmergencia, telefoneDeEmergencia);
}

