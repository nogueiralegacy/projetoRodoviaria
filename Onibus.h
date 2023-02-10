#ifndef PROJETORODOVIARIA_ONIBUS_H
#define PROJETORODOVIARIA_ONIBUS_H

typedef struct onibus Onibus;

Onibus *iniciaOnibus(char codigoDoOnibus[12]);

char **criaAssentos(int qntFileira, int qntColunas);

char *getCodigoDoOnibus(Onibus *onibus);

int getQuantidadeDeAssentos(Onibus *onibus);

void setQuantidadeDeAssentos(Onibus *onibus, int quantidadeDeAssentos);

char **getAssentos(Onibus *onibus);

int getQuantidadeDeFileiras(Onibus *onibus);

int getQuantidadeDeColunas(Onibus *onibus);

void liberaAssentos(char **assentos, int qntFileira);

void liberaOnibus(Onibus *onibus);

#endif //PROJETORODOVIARIA_ONIBUS_H
