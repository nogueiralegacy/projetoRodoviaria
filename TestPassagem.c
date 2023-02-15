#include "Passagem.h"
#include "Passageiro.h"
#include "stdio.h"

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_DEFAULT "\033[0m"
#define ANSI_COLOR_GREEN "\x1b[32m"

void testIniciaPassagemAtributos() {
    char *codigoDaPassagem = "12345678910";
    int fileira = 1;
    int coluna = 1;
    float valor = 100.0;

    // Cria um passageiro com atributos
    char *nome = "Joao";
    char *cpf = "12345678910";
    char *telefone = "10987654321";
    char *email = "joao@gmail.com";
    char *telefoneDeEmergencia = "01020304050";
    Passageiro *passageiro = iniciaPassageiro(nome, cpf, telefone, email, telefoneDeEmergencia);


    struct passagem *passagem = iniciaPassagem(codigoDaPassagem, fileira, coluna, valor, passageiro);

    if (strcmp(getCodigoDaPassagem(passagem), codigoDaPassagem) == 0) {
        if (getFileira(passagem) == fileira) {
            if (getColuna(passagem) == coluna) {
                if (getValor(passagem) == valor) {
                    if (strcmp(getCpf(passageiro), cpf) == 0) {
                        printf(ANSI_COLOR_GREEN "testIniciaPassagemAtributos(): Success!\n" ANSI_DEFAULT);
                    }
                }
            }
        }
    } else {
        printf(ANSI_COLOR_RED "testIniciaPassagemAtributos(): Failed!\n" ANSI_DEFAULT);
    }
    liberaPassagem(passagem);
}

void agrupaTestesPassagem() {
    testIniciaPassagemAtributos();
}