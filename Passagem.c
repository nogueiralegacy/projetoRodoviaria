#include <string.h>
#include <stdlib.h>

struct passagem {
    char codigoDaPassagem[12];
    int fileira;
    int coluna;
    float valor;
    struct passageiro *passageiro;
};

typedef struct passagem Passagem;

Passagem *iniciaPassagem(char codigoDaPassagem[12], int fileira, int coluna, float valor, struct passageiro *passageiro) {
    Passagem *passagem = (Passagem *) malloc(sizeof(Passagem));
    strcpy(passagem->codigoDaPassagem, codigoDaPassagem);
    passagem->fileira = fileira;
    passagem->coluna = coluna;
    passagem->valor = valor;
    passagem->passageiro = passageiro;

    return passagem;
}

Passagem *criaPassagem() {
    Passagem *passagem = (Passagem *) malloc(sizeof(Passagem));
    strcpy(passagem->codigoDaPassagem, "");
    passagem->fileira = 0;
    passagem->coluna = 0;
    passagem->valor = 0.0;
    passagem->passageiro = NULL;

    return passagem;
}

char *getCodigoDaPassagem(Passagem *passagem) {
    return passagem->codigoDaPassagem;
}

int getFileira(Passagem *passagem) {
    return passagem->fileira;
}
int getColuna(Passagem *passagem) {
    return passagem->coluna;
}

float getValor(Passagem *passagem) {
    return passagem->valor;
}

struct passageiro *getPassageiro(Passagem *passagem) {
    return passagem->passageiro;
}

void setCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]) {
    strcpy(passagem->codigoDaPassagem, codigoDaPassagem);
}

void setFileira(Passagem *passagem, int fileira) {
    passagem->fileira = fileira;
}

void setColuna(Passagem *passagem, int coluna) {
    passagem->coluna = coluna;
}

void setValor(Passagem *passagem, float valor) {
    passagem->valor = valor;
}

void setPassageiro(Passagem *passagem, struct passageiro *passageiro) {
    passagem->passageiro = passageiro;
}