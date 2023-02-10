#ifndef PROJETORODOVIARIA_VIAGEM_H
#define PROJETORODOVIARIA_VIAGEM_H

#include <time.h>

typedef struct viagem Viagem;

Viagem *iniciaViagem(char codigoDaViagem[12], char companhia[50], char origem[50], char destino[50], time_t dataEHoraDeSaida, struct passagem *passagens, struct onibus *onibus);

Viagem *criaViagem();

char *getCodigoDaViagem(Viagem *viagem);

char *getCompanhia(Viagem *viagem);

char *getOrigem(Viagem *viagem);

char *getDestino(Viagem *viagem);

time_t getDataEHoraDeSaida(Viagem *viagem);

struct passagem *getPassagens(Viagem *viagem);

struct onibus *getOnibus(Viagem *viagem);

void setCodigodaViagem(Viagem *viagem, char codigoDaViagem[12]);

void setCompanhia(Viagem *viagem, char companhia[50]);

void setOrigem(Viagem *viagem, char origem[50]);

void setDestino(Viagem *viagem, char destino[50]);

void setDataEHoraDeSaida(Viagem *viagem, time_t dataEHoraDeSaida);

void setPassagens(Viagem *viagem, struct passagem *passagens);

void setOnibus(Viagem *viagem, struct onibus *onibus);
#endif //PROJETORODOVIARIA_VIAGEM_H
