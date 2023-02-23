#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#ifndef PROJETORODOVIARIA_ONIBUS_H
#define PROJETORODOVIARIA_ONIBUS_H

typedef struct onibus Onibus;

struct onibus *iniciaOnibus(char codigoDoOnibus[12]);

struct onibus *criaOnibus();

char **criaAssentos(int qntFileira, int qntColunas);

char *getCodigoDoOnibus(Onibus *onibus);

int getQuantidadeDeAssentos(Onibus *onibus);

void setQuantidadeDeAssentos(Onibus *onibus, int quantidadeDeAssentos);

char **getAssentos(Onibus *onibus);

void setAssento(Onibus *onibus, int fileira, int coluna);

int getQuantidadeDeFileiras(Onibus *onibus);

int getQuantidadeDeColunas(Onibus *onibus);

void liberaAssentos(char **assentos);

void liberaOnibus(Onibus *onibus);

void salvarOnibus(struct onibus *onibus, char *nomeArquivo);

void recuperaOnibus(struct onibus *onibus, char *nomeArquivo);

#endif //PROJETORODOVIARIA_ONIBUS_H
