#ifndef PROJETORODOVIARIA_VIAGEM_H
#define PROJETORODOVIARIA_VIAGEM_H

#include <time.h>

typedef struct viagem Viagem;

Viagem *iniciaViagem(char codigoDaViagem[12], char companhia[50], char origem[50], char destino[50], time_t dataEHoraDeSaida, struct passagem *passagens, struct onibus *onibus);

Viagem *criaViagem();

#endif //PROJETORODOVIARIA_VIAGEM_H
