#include "Viagem.h"
#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Passagem.h"
#include "Onibus.h"

struct viagem {
    char codigoDaViagem[12];
    char companhia[50];
    char origem[50];
    char destino[50];
    time_t dataEHoraDeSaida;
    struct passagem *passagens;
    struct onibus *onibus;
};

typedef struct viagem Viagem;

Viagem *iniciaViagem(char codigoDaViagem[12], char companhia[50], char origem[50], char destino[50], time_t dataEHoraDeSaida, struct passagem *passagens, struct onibus *onibus) {
    Viagem *viagem = (Viagem *) malloc(sizeof(Viagem));

    strcpy(viagem->codigoDaViagem, codigoDaViagem);
    strcpy(viagem->companhia, companhia);
    strcpy(viagem->origem, origem);
    strcpy(viagem->destino, destino);
    viagem->dataEHoraDeSaida = dataEHoraDeSaida;
    viagem->passagens = passagens;
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
    viagem->passagens = NULL;
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

Passagem *getPassagens(Viagem *viagem) {
    return viagem->passagens;
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

void setPassagens(Viagem *viagem, Passagem *passagens) {
    viagem->passagens = passagens;
}

void setOnibus(Viagem *viagem, Onibus *onibus) {
    viagem->onibus = onibus;
}