#include <string.h>

struct passagem {
    char codigoDaPassagem[12];
    char fileira;
    char coluna;
    float valor;
    // Executada ou Pendente (Quando uma passagem é executada significa que
    // o passageiro já embarcou no ônibus)
    char status[10];
    struct passageiro *passageiro;
};

typedef struct passagem Passagem;


char *getCodigoDaPassagem(Passagem *passagem) {
    return passagem->codigoDaPassagem;
}

char getFileira(Passagem *passagem) {
    return passagem->fileira;
}
char getColuna(Passagem *passagem) {
    return passagem->coluna;
}

float getValor(Passagem *passagem) {
    return passagem->valor;
}

char *getStatus(Passagem *passagem) {
    return passagem->status;
}

struct passageiro *getPassageiro(Passagem *passagem) {
    return passagem->passageiro;
}

void setCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]) {
    strcpy(passagem->codigoDaPassagem, codigoDaPassagem);
}

void setFileira(Passagem *passagem, char fileira) {
    passagem->fileira = fileira;
}

void setColuna(Passagem *passagem, char coluna) {
    passagem->coluna = coluna;
}

void setValor(Passagem *passagem, float valor) {
    passagem->valor = valor;
}

void setStatus(Passagem *passagem, char status[10]) {
    strcpy(passagem->status, status);
}

void setPassageiro(Passagem *passagem, struct passageiro *passageiro) {
    passagem->passageiro = passageiro;
}