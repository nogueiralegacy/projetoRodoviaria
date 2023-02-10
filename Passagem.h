#ifndef PROJETORODOVIARIA_PASSAGEM_H
#define PROJETORODOVIARIA_PASSAGEM_H

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
struct Passagem *iniciaPassagem(char codigoDaPassagem[12], char fileira, char coluna, float valor, struct passageiro *passageiro);

/**
 * Construtor vazio, retorna um endereço (instância) de Passagem
 * com todos os campos vazios.
 *
 * @return Instância de Passagem
 */
Passagem *criaPassagem();

void getCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]);

char getFileira(Passagem *passagem);

char getColuna(Passagem *passagem);

float getValor(Passagem *passagem);

struct passageiro *getPassageiro(Passagem *passagem);

void setCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]);

void setFileira(Passagem *passagem, char fileira);

void setColuna(Passagem *passagem, char coluna);

void setValor(Passagem *passagem, float valor);

void setPassageiro(Passagem *passagem, struct passageiro *passageiro);

#endif //PROJETORODOVIARIA_PASSAGEM_H
