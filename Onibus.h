#include <string.h>
#include <stdlib.h>

#ifndef PROJETORODOVIARIA_ONIBUS_H
#define PROJETORODOVIARIA_ONIBUS_H

typedef struct onibus Onibus;

struct onibus *iniciaOnibus(char codigoDoOnibus[12]);

char **criaAssentos(int qntFileira, int qntColunas);

char *getCodigoDoOnibus(Onibus *onibus);

int getQuantidadeDeAssentos(Onibus *onibus);

void setQuantidadeDeAssentos(Onibus *onibus, int quantidadeDeAssentos);

char **getAssentos(Onibus *onibus);

int getQuantidadeDeFileiras(Onibus *onibus);

int getQuantidadeDeColunas(Onibus *onibus);

void liberaAssentos(char **assentos);

void liberaOnibus(Onibus *onibus);

#endif //PROJETORODOVIARIA_ONIBUS_H
