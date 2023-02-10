#ifndef ONIBUS_H
#define ONIBUS_H

typedef struct onibus Onibus;

Onibus *iniciaOnibus(char codigoDoOnibus[12]);

char *getCodigoDoOnibus(Onibus *onibus);

int getQuantidadeDeAssentos(Onibus *onibus);

void setQuantidadeDeAssentos(Onibus *onibus, int quantidadeDeAssentos);

#endif //ONIBUS_H
