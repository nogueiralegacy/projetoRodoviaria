#ifndef PROJETORODOVIARIA_PASSAGEM_H
#define PROJETORODOVIARIA_PASSAGEM_H

#include "Passageiro.h"

typedef struct passagem Passagem;

/**
 * Construtor com todos os atributos de passagem
 *
 * @param codigoDaPassagem Código da Passagem
 * @param fileira Fileira do assento da passagem
 * @param coluna Coluna do assento da passagem
 * @param valor Valor pago pela passagem
 * @param passageiro Passageiro que comprou a passagem
 *
 * @return Um endereço de memória
 */
struct passagem *iniciaPassagem(char codigoDaPassagem[12], int fileira, int coluna, float valor, struct passageiro *passageiro);

/**
 * Construtor vazio, retorna um endereço (instância) de Passagem
 * com todos os campos vazios.
 *
 * @return Instância de Passagem
 */
struct passagem *criaPassagem();

/**
 * Destrutor de Passagem
 *
 * @param passagem Instância de Passagem
 */
void liberaPassagem(struct passagem *passagem);

char *getCodigoDaPassagem(Passagem *passagem);

int getFileira(Passagem *passagem);

int getColuna(Passagem *passagem);

float getValor(Passagem *passagem);

struct passageiro *getPassageiro(Passagem *passagem);

void setCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]);

void setFileira(Passagem *passagem, int fileira);

void setColuna(Passagem *passagem, int coluna);

void setValor(Passagem *passagem, float valor);

void setPassageiro(Passagem *passagem, struct passageiro *passageiro);

#endif //PROJETORODOVIARIA_PASSAGEM_H
