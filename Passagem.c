#include "Passagem.h"

//No arquivo de passagem será guardado o CPF do passageiro
const char *FORMATO_PASSAGEM_OUT = "(%s,%s,%d,%d,%f)\n";
const char *FORMATO_PASSAGEM_IN = "(%[^,],%[^,],%d,%d,%f)\n";

struct passagem {
    struct passageiro *passageiro;
    char codigoDaPassagem[12];
    int fileira;
    int coluna;
    float valor;
};

typedef struct passagem Passagem;

Passagem *iniciaPassagem(char codigoDaPassagem[12], int fileira, int coluna, float valor, struct passageiro *passageiro) {
    Passagem *passagem = (Passagem *) malloc(sizeof(Passagem));
    strcpy(passagem->codigoDaPassagem, codigoDaPassagem);
    passagem->fileira = fileira;
    passagem->coluna = coluna;
    passagem->valor = valor;
    passagem->passageiro = passageiro;

    return passagem;
}

Passagem *criaPassagem() {
    Passagem *passagem = (Passagem *) malloc(sizeof(Passagem));
    strcpy(passagem->codigoDaPassagem, "");
    passagem->fileira = 0;
    passagem->coluna = 0;
    passagem->valor = 0.0;
    passagem->passageiro = NULL;

    return passagem;
}

void liberaPassagem(Passagem *passagem) {
    liberaPassageiro(passagem->passageiro);
    free(passagem);
}

char *getCodigoDaPassagem(Passagem *passagem) {
    return passagem->codigoDaPassagem;
}

int getFileira(Passagem *passagem) {
    return passagem->fileira;
}
int getColuna(Passagem *passagem) {
    return passagem->coluna;
}

float getValor(Passagem *passagem) {
    return passagem->valor;
}

struct passageiro *getPassageiro(Passagem *passagem) {
    return passagem->passageiro;
}

void setCodigoDaPassagem(Passagem *passagem, char codigoDaPassagem[12]) {
    strcpy(passagem->codigoDaPassagem, codigoDaPassagem);
}

void setFileira(Passagem *passagem, int fileira) {
    passagem->fileira = fileira;
}

void setColuna(Passagem *passagem, int coluna) {
    passagem->coluna = coluna;
}

void setValor(Passagem *passagem, float valor) {
    passagem->valor = valor;
}

void setPassageiro(Passagem *passagem, struct passageiro *passageiro) {
    passagem->passageiro = passageiro;
}

void salvaPassagem(Passagem *passagem, char *nomeDoArquivo) {
    FILE *file;

    file = fopen(nomeDoArquivo, "a");
    fprintf(file, FORMATO_PASSAGEM_OUT, getCpf(passagem->passageiro), passagem->codigoDaPassagem, passagem->fileira, passagem->coluna, passagem->valor);
    fclose(file);
}

void recuperaPassagem(Passagem *passagem, char *filePassagens, char *filePassageiros, char *codigoDaPassagem) {
    FILE *arquivo;
    arquivo = fopen(filePassagens, "r");
    Passageiro *passageiro = criaPassageiro();
    char linha[200];
    while (fgets(linha, 200, arquivo) != NULL) {
        char cpf[12];
        sscanf(linha, FORMATO_PASSAGEM_IN, cpf, passagem->codigoDaPassagem, &passagem->fileira, &passagem->coluna, &passagem->valor);
        recuperaPassageiro(passageiro, filePassageiros, cpf);
        setPassageiro(passagem, passageiro);
        if (strcmp(passagem->codigoDaPassagem, codigoDaPassagem) == 0) {
            break;
        }
    }
    fclose(arquivo);
}

Passagem **recuperaTodasPassagens(int *indice, char *filePassagens, char *filePassageiros) {
    FILE *arquivo;
    arquivo = fopen(filePassagens, "r");



    char linha[200];
    Passagem **passagens = (Passagem **) malloc(sizeof(Passagem *) * 10);
    *indice = 0;
    while (fgets(linha, 200, arquivo) != NULL) {
        char cpf[12];
        Passagem *passagem = criaPassagem();
        Passageiro *passageiro = criaPassageiro();

        sscanf(linha, FORMATO_PASSAGEM_IN, cpf, passagem->codigoDaPassagem, &passagem->fileira, &passagem->coluna, &passagem->valor);

        recuperaPassageiro(passageiro, filePassageiros, cpf);
        setPassageiro(passagem, passageiro);
        passagens[*indice] = passagem;
        *indice = *indice + 1;
    }

    fclose(arquivo);

    return passagens;
}