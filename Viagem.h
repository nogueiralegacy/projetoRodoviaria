#include "Passageiro.h"
#include <time.h>
#include "Passagem.h"
#include "Onibus.h"

#ifndef PROJETORODOVIARIA_VIAGEM_H
#define PROJETORODOVIARIA_VIAGEM_H

typedef struct passagemVendida PassagemVendida;

typedef struct listaPassagensVendidas ListaPassagensVendidas;

struct passagemVendida *iniciaPassagemVendida(Passagem *passagem);

struct listaPassagensVendidas *iniciaListaPassagensVendidas();

typedef struct viagem Viagem;

struct viagem *iniciaViagem(char codigoDaViagem[12], char companhia[50], char origem[50], char destino[50], char dataEHoraDeSaida[16], struct onibus *onibus);

struct viagem *criaViagem();

void liberaViagem(Viagem *viagem);

void liberaPassagemVendida(struct passagemVendida *passagemVendida);

void liberaListaDePassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas);

char *getCodigoDaViagem(Viagem *viagem);

char *getCompanhia(Viagem *viagem);

char *getOrigem(Viagem *viagem);

char *getDestino(Viagem *viagem);

char *getDataEHoraDeSaida(Viagem *viagem);

struct onibus *getOnibus(Viagem *viagem);

void setCodigoDaViagem(Viagem *viagem, char codigoDaViagem[12]);

void setCompanhia(Viagem *viagem, char companhia[50]);

void setOrigem(Viagem *viagem, char origem[50]);

void setDestino(Viagem *viagem, char destino[50]);

void setDataEHoraDeSaida(Viagem *viagem, char dataEHoraDeSaida[16]);

void setOnibus(Viagem *viagem, struct onibus *onibus);

struct passagem *getPassagem(struct passagemVendida *passagemVendida);

struct passagemVendida *getProximo(struct passagemVendida *listaPassagensVendidas);

void setPassagem(struct passagemVendida *passagemVendida, struct passagem *passagem);

void setProximo(struct passagemVendida *passagemVendida, struct passagemVendida *proximo);

void insereListaPassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas, struct passagem *passagem);

struct passagemVendida *getInicioListaPassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas);

struct passagemVendida *getFimListaPassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas);

int getQuantidadeDePassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas);

void setInicioListaPassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas, struct passagemVendida *inicio);

void setFimListaPassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas, struct passagemVendida *fim);

void setQuantidadeDePassagensVendidas(struct listaPassagensVendidas *listaPassagensVendidas, int quantidadeDePassagensVendidas);

void salvaViagem(Viagem *viagem, char *nomeDoArquivo);

void recuperaViagem(Viagem *viagem, char *fileViagem, char *fileOnibus, char *filePassagem);

#endif //PROJETORODOVIARIA_VIAGEM_H
