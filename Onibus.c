#include "Onibus.h"

#define FILEIRAS 12
#define COLUNAS 4

struct onibus {
    char **assentos;
    char codigoDoOnibus[12];
    int quantidadeDeAssentos;
};

typedef struct onibus Onibus;

char **criaAssentos(int qntFileira, int qntColunas) {
    char **assentos = (char **) malloc(qntFileira * sizeof(char *));
    char *assentosAux;

    for (int indice = 0; indice < qntFileira; indice++) {
        assentosAux = (char *) malloc(qntColunas * sizeof(char));
        memset(assentosAux, (char) 'L', qntColunas * sizeof(char));
        assentos[indice] = assentosAux;
    }

    return assentos;
}

Onibus *iniciaOnibus(char codigoDoOnibus[12]) {
    Onibus *onibus = (Onibus *) malloc(sizeof(Onibus));
    onibus->assentos = criaAssentos(FILEIRAS, COLUNAS);
    onibus->quantidadeDeAssentos = FILEIRAS * COLUNAS;
    strcpy(onibus->codigoDoOnibus, codigoDoOnibus);
    return onibus;
}

Onibus *criaOnibus() {
    Onibus *onibus = (Onibus *) malloc(sizeof(Onibus));
    strcpy(onibus->codigoDoOnibus, "");
    onibus->assentos = criaAssentos(FILEIRAS, COLUNAS);
    onibus->quantidadeDeAssentos = FILEIRAS * COLUNAS;
    return onibus;
}

void liberaAssentos(char **assentos) {
    for (int indice = 0; indice < FILEIRAS; indice++) {
        free(assentos[indice]);
    }
    free(assentos);
}

void liberaOnibus(Onibus *onibus) {
    liberaAssentos(onibus->assentos);
    free(onibus);
}

char *getCodigoDoOnibus(Onibus *onibus) {
    return onibus->codigoDoOnibus;
}

int getQuantidadeDeAssentos(Onibus *onibus) {
    return onibus->quantidadeDeAssentos;
}

char **getAssentos(Onibus *onibus) {
    return onibus->assentos;
}

void setAssento(Onibus *onibus, int fileira, int coluna) {
    onibus->assentos[fileira][coluna] = 'O';
}

int getQuantidadeDeFileiras(Onibus *onibus) {
    return FILEIRAS;
}

int getQuantidadeDeColunas(Onibus *onibus) {
    return COLUNAS;
}

void salvarOnibus(Onibus *onibus, char *nomeDoArquivo) {
    FILE *file;

    file = fopen(nomeDoArquivo, "w");
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            fprintf(file, "%c,", onibus->assentos[i][j]);
        }
    }

    fprintf(file, "%s,", onibus->codigoDoOnibus);
    fprintf(file, "%d\n", onibus->quantidadeDeAssentos);
    fclose(file);
}

void recuperaOnibus(Onibus *onibus, char *nomeDoArquivo) {
    FILE *file;

    file = fopen(nomeDoArquivo, "r");
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < FILEIRAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            fscanf(file, "%c,", &onibus->assentos[i][j]);
        }
    }
    fscanf(file, "%s,", onibus->codigoDoOnibus);
    fscanf(file, "%d\n", &onibus->quantidadeDeAssentos);
}
