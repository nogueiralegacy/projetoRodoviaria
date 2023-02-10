#include "Viagem.h"

struct passagemVendida {
    struct passagem *passagem;
    struct passagemVendida *proximo;
};

typedef struct passagemVendida PassagemVendida;


PassagemVendida *iniciaPassagemVendida(Passagem *passagem) {
    PassagemVendida *passagemVendida = (PassagemVendida *) malloc(sizeof(PassagemVendida));
    passagemVendida->passagem = passagem;
    passagemVendida->proximo = NULL;

    return passagemVendida;
}

struct listaPassagensVendidas {
    int quantidade;
    struct passagemVendida *inicio;
    struct passagemVendida *fim;
};

typedef struct listaPassagensVendidas ListaPassagensVendidas;

ListaPassagensVendidas *iniciaListaPassagensVendidas() {
    ListaPassagensVendidas *listaPassagensVendidas = (ListaPassagensVendidas *) malloc(sizeof(ListaPassagensVendidas));
    listaPassagensVendidas->quantidade = 0;
    listaPassagensVendidas->inicio = NULL;
    listaPassagensVendidas->fim = NULL;

    return listaPassagensVendidas;
}

struct viagem {
    char codigoDaViagem[12];
    char companhia[50];
    char origem[50];
    char destino[50];
    time_t dataEHoraDeSaida;
    // Passagens vendidas
    struct listaPassagensVendidas *listaPassagensVendidas;
    struct onibus *onibus;
};

typedef struct viagem Viagem;

Viagem *iniciaViagem(char codigoDaViagem[12], char companhia[50],
                     char origem[50],char destino[50],time_t dataEHoraDeSaida,
                     struct listaPassagensVendidas *listaPassagensVendidas,struct onibus *onibus) {
    Viagem *viagem = (Viagem *) malloc(sizeof(Viagem));

    strcpy(viagem->codigoDaViagem, codigoDaViagem);
    strcpy(viagem->companhia, companhia);
    strcpy(viagem->origem, origem);
    strcpy(viagem->destino, destino);
    viagem->dataEHoraDeSaida = dataEHoraDeSaida;
    viagem->listaPassagensVendidas = listaPassagensVendidas;
    viagem->onibus = onibus;

    return viagem;
}

Viagem *criaViagem() {
    Viagem *viagem = (Viagem *) malloc(sizeof(Viagem));
    strcpy(viagem->codigoDaViagem, "");
    strcpy(viagem->companhia, "");
    strcpy(viagem->origem, "");
    strcpy(viagem->destino, "");
    viagem->dataEHoraDeSaida = 0;
    viagem->listaPassagensVendidas = NULL;
    viagem->onibus = NULL;

    return viagem;
}
void liberaViagem(Viagem *viagem) {
    free(viagem);
}

char *getCodigoDaViagem(Viagem *viagem) {
    return viagem->codigoDaViagem;
}

char *getCompanhia(Viagem *viagem) {
    return viagem->companhia;
}

char *getOrigem(Viagem *viagem) {
    return viagem->origem;
}

char *getDestino(Viagem *viagem) {
    return viagem->destino;
}

time_t getDataEHoraDeSaida(Viagem *viagem) {
    return viagem->dataEHoraDeSaida;
}

Onibus *getOnibus(Viagem *viagem) {
    return viagem->onibus;
}

void setCodigoDaViagem(Viagem *viagem, char codigoDaViagem[12]) {
    strcpy(viagem->codigoDaViagem, codigoDaViagem);
}

void setCompanhia(Viagem *viagem, char companhia[50]) {
    strcpy(viagem->companhia, companhia);
}

void setOrigem(Viagem *viagem, char origem[50]) {
    strcpy(viagem->origem, origem);
}

void setDestino(Viagem *viagem, char destino[50]) {
    strcpy(viagem->destino, destino);
}

void setDataEHoraDeSaida(Viagem *viagem, time_t dataEHoraDeSaida) {
    viagem->dataEHoraDeSaida = dataEHoraDeSaida;
}
void setOnibus(Viagem *viagem, Onibus *onibus) {
    viagem->onibus = onibus;
}

Passagem *getPassagem(PassagemVendida *passagemVendida) {
    return passagemVendida->passagem;
}

PassagemVendida *getProximo(PassagemVendida *passagemVendida) {
    return passagemVendida->proximo;
}

void setPassagem(PassagemVendida *passagemVendida, Passagem *passagem) {
    passagemVendida->passagem = passagem;
}

void setProximo(PassagemVendida *passagemVendida, PassagemVendida *proximo) {
    passagemVendida->proximo = proximo;
}