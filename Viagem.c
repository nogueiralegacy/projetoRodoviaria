#include <string.h>
#include <stdlib.h>
#include <time.h>
#include "Passagem.h"
#include "Onibus.h"

struct Viagem {
    char codigoDaViagem[12];
    char companhia[50];
    char origem[50];
    char destino[50];
    time_t dataEHoraDeSaida;
    struct passagem *passagens;
    struct onibus *onibus;
};

typedef struct Viagem Viagem;

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