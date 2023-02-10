#include <string.h>
#include <stdlib.h>

#define FILEIRA 12
#define POLTRONA 4

struct onibus {
    char assentos[FILEIRA][POLTRONA];
    char codigoDoOnibus[12];
    int quantidadeDeAssentos;
};

typedef struct onibus Onibus;

Onibus *iniciaOnibus(char codigoDoOnibus[12]) {
    Onibus *onibus = (Onibus *) malloc(sizeof(Onibus));
    onibus->quantidadeDeAssentos = FILEIRA * POLTRONA;
    strcpy(onibus->codigoDoOnibus, codigoDoOnibus);
    for (int i = 0; i < FILEIRA; i++) {
        for (int j = 0; j < POLTRONA; j++) {
            onibus->assentos[i][j] = 'L';
        }
    }
    return onibus;
}

char *getCodigoDoOnibus(Onibus *onibus) {
    return onibus->codigoDoOnibus;
}

int getQuantidadeDeAssentos(Onibus *onibus) {
    return onibus->quantidadeDeAssentos;
}

void setQuantidadeDeAssentos(Onibus *onibus, int quantidadeDeAssentos) {
    onibus->quantidadeDeAssentos = quantidadeDeAssentos;
}