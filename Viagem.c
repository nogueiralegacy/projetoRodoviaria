#include "Viagem.h"

const char *FORMATO_VIAGEM_OUT = "(%s,%s,%s,%s,%s)\n";
const char *FORMATO_VIAGEM_IN = "(%[^,],%[^,],%[^,],%[^,],%[^)])\n";

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
    char dataEHoraDeSaida[16];
    // Passagens vendidas
    struct listaPassagensVendidas *listaPassagensVendidas;
    struct onibus *onibus;
};

typedef struct viagem Viagem;

Viagem *iniciaViagem(char codigoDaViagem[12], char companhia[50],
                     char origem[50], char destino[50], char dataEHoraDeSaida[16], struct onibus *onibus) {
                     
    Viagem *viagem = (Viagem *) malloc(sizeof(Viagem));

    strcpy(viagem->codigoDaViagem, codigoDaViagem);
    strcpy(viagem->companhia, companhia);
    strcpy(viagem->origem, origem);
    strcpy(viagem->destino, destino);
    strcpy(viagem->dataEHoraDeSaida, dataEHoraDeSaida);
    viagem->listaPassagensVendidas = iniciaListaPassagensVendidas();
    viagem->onibus = onibus;

    return viagem;
}

Viagem *criaViagem() {
    Viagem *viagem = (Viagem *) malloc(sizeof(Viagem));
    strcpy(viagem->codigoDaViagem, "");
    strcpy(viagem->companhia, "");
    strcpy(viagem->origem, "");
    strcpy(viagem->destino, "");
    strcpy(viagem->dataEHoraDeSaida, "");
    viagem->listaPassagensVendidas = iniciaListaPassagensVendidas();
    viagem->onibus = NULL;

    return viagem;
}

void liberaViagem(Viagem *viagem) {
    free(viagem);
}

void liberaPassagemVendida(PassagemVendida *passagemVendida) {
    liberaPassagem(passagemVendida->passagem);
    free(passagemVendida);
}

void liberaListaDePassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas) {
    PassagemVendida *passagemVendidaAux = listaPassagensVendidas->inicio;

    while (passagemVendidaAux != NULL) {
        PassagemVendida *passagemVendidaAux2 = passagemVendidaAux->proximo;

        liberaPassagemVendida(passagemVendidaAux);

        passagemVendidaAux = passagemVendidaAux2;
    }

    free(listaPassagensVendidas);
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

char *getDataEHoraDeSaida(Viagem *viagem) {
    return viagem->dataEHoraDeSaida;
}

Onibus *getOnibus(Viagem *viagem) {
    return viagem->onibus;
}

ListaPassagensVendidas *getListaPassagensVendidas(Viagem *viagem) {
    return viagem->listaPassagensVendidas;
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

void setDataEHoraDeSaida(Viagem *viagem, char dataEHoraDeSaida[16]) {
    strcpy(viagem->dataEHoraDeSaida, dataEHoraDeSaida);
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

void insereListaPassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas, Passagem *passagem) {
    PassagemVendida *passagemVendida = iniciaPassagemVendida(passagem);

    if (listaPassagensVendidas->quantidade == 0) {
        listaPassagensVendidas->inicio = passagemVendida;
        listaPassagensVendidas->fim = passagemVendida;
    } else {
        listaPassagensVendidas->fim->proximo = passagemVendida;
        listaPassagensVendidas->fim = passagemVendida;
    }
    listaPassagensVendidas->quantidade++;
}

PassagemVendida *getInicioListaPassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas) {
    return listaPassagensVendidas->inicio;
}

PassagemVendida *getPrimeiraPassagemVendida(Viagem *viagem) {
    return viagem->listaPassagensVendidas->inicio;
}

PassagemVendida *getFimListaPassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas) {
    return listaPassagensVendidas->fim;
}

int getQuantidadeDePassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas) {
    return listaPassagensVendidas->quantidade;
}

void setInicioListaPassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas, PassagemVendida *inicio) {
    listaPassagensVendidas->inicio = inicio;
}

void setFimListaPassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas, PassagemVendida *fim) {
    listaPassagensVendidas->fim = fim;
}

void setQuantidadeDePassagensVendidas(ListaPassagensVendidas *listaPassagensVendidas, int quantidade) {
    listaPassagensVendidas->quantidade = quantidade;
}

void salvaViagem(Viagem *viagem, char *nomeArquivo) {
    FILE *arquivo = fopen(nomeArquivo, "w");

    fprintf(arquivo, FORMATO_VIAGEM_OUT, viagem->codigoDaViagem, viagem->companhia, viagem->origem, viagem->destino, viagem->dataEHoraDeSaida);

    fclose(arquivo);
}

void recuperaViagem(Viagem *viagem, char *fileViagem, char *fileOnibus, char *filePassagens, char *filePassageiros) {
    liberaListaDePassagensVendidas(viagem->listaPassagensVendidas);
    viagem->listaPassagensVendidas = iniciaListaPassagensVendidas();

    FILE *arquivo = fopen(fileViagem, "r");

    fscanf(arquivo, FORMATO_VIAGEM_IN, viagem->codigoDaViagem, viagem->companhia, viagem->origem, viagem->destino, viagem->dataEHoraDeSaida);

    Onibus *onibus = criaOnibus();
    recuperaOnibus(onibus, fileOnibus);
    viagem->onibus = onibus;

    int *indice = (int *) malloc(sizeof(int));
    *indice = 0;
    Passagem **passagens = recuperaTodasPassagens(indice, filePassagens, filePassageiros);

    for (int count = 0; count < *indice; count++) {
        insereListaPassagensVendidas(viagem->listaPassagensVendidas, passagens[count]);
    }

    fclose(arquivo);
}