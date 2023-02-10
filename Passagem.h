#ifndef PROJETORODOVIARIA_PASSAGEM_H
#define PROJETORODOVIARIA_PASSAGEM_H

typedef struct passagem Passagem;

void getCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]);

char getFileira(Passagem *passagem);

char getColuna(Passagem *passagem);

float getValor(Passagem *passagem);

char *getStatus(Passagem *passagem);

struct passageiro *getPassageiro(Passagem *passagem);

void setCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]);

void setFileira(Passagem *passagem, char fileira);

void setColuna(Passagem *passagem, char coluna);

void setValor(Passagem *passagem, float valor);

void setStatus(Passagem *passagem, char status[10]);

void setPassageiro(Passagem *passagem, struct passageiro *passageiro);

#endif //PROJETORODOVIARIA_PASSAGEM_H
